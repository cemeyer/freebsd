/*	$OpenBSD: arc4random.h,v 1.4 2015/01/15 06:57:18 deraadt Exp $	*/

/*
 * Copyright (c) 1996, David Mazieres <dm@uun.org>
 * Copyright (c) 2008, Damien Miller <djm@openbsd.org>
 * Copyright (c) 2013, Markus Friedl <markus@openbsd.org>
 * Copyright (c) 2014, Theo de Raadt <deraadt@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * $FreeBSD$
 */

/*
 * Stub functions for portability.
 */
#include <sys/elf.h>
#include <sys/endian.h>
#include <sys/mman.h>
#include <sys/time.h>	/* for sys/vdso.h only. */
#include <sys/vdso.h>
#include <machine/atomic.h>

#include <err.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>

/*
 * The root seed version is a 64-bit counter, but we truncate it to a 32-bit
 * value on ILP32 userspace (including compat32).
 */
#ifdef __LP64__
#define	fxrng_load_acq_generation(x)	atomic_load_acq_64(x)
static uint64_t	*fxrng_root_generationp;
#else
#define	fxrng_load_acq_generation(x)	atomic_load_acq_32(x)
static uint32_t	*fxrng_root_generationp;
#endif

static pthread_mutex_t	arc4random_mtx = PTHREAD_MUTEX_INITIALIZER;
#define	_ARC4_LOCK()						\
	do {							\
		if (__isthreaded)				\
			_pthread_mutex_lock(&arc4random_mtx);	\
	} while (0)

#define	_ARC4_UNLOCK()						\
	do {							\
		if (__isthreaded)				\
			_pthread_mutex_unlock(&arc4random_mtx);	\
	} while (0)

static inline void
_getentropy_fail(void)
{
	raise(SIGKILL);
}

static inline int
_rs_allocate(struct _rs **rsp, struct _rsx **rsxp)
{
	struct vdso_fxrng_generation *vdso_fxrngp;
	struct {
		struct _rs rs;
		struct _rsx rsx;
	} *p;
	int error;

	if ((p = mmap(NULL, sizeof(*p), PROT_READ|PROT_WRITE,
	    MAP_ANON|MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (-1);
	if (minherit(p, sizeof(*p), INHERIT_ZERO) == -1) {
		munmap(p, sizeof(*p));
		return (-1);
	}
	error = _elf_aux_info(AT_FXRNG, &vdso_fxrngp, sizeof(vdso_fxrngp));
	if (error == 0) {
		if (vdso_fxrngp->fx_vdso_version != VDSO_FXRNG_VER_1) {
			munmap(p, sizeof(*p));
			return (-1);
		}

#ifdef __LP64__
		fxrng_root_generationp = &vdso_fxrngp->fx_generation;
#else
		fxrng_root_generationp = &vdso_fxrngp->fx_generation32;
#endif
	} else {
#ifdef NOTYET
		/*
		 * Transition period: new userspace on old kernel.  Should
		 * become a hard error at some point, if the scheme is adopted.
		 */
		errno = error;
		return (-1);
#endif
	}

	*rsp = &p->rs;
	*rsxp = &p->rsx;
	return (0);
}

/*
 * This isn't detecting fork; we're just using the existing callback from
 * _rs_stir_if_needed() to force arc4random(3) to reseed if the fenestrasX root
 * seed version has changed.  (That is, the root random(4) has reseeded from
 * pooled entropy.)
 */
static inline void
_rs_forkdetect(void)
{
	if (__predict_false(rs == NULL || rsx == NULL))
		return;
	if (fxrng_root_generationp == NULL)
		return;
	if (__predict_true(rsx->rs_seed_generation ==
	    fxrng_load_acq_generation(fxrng_root_generationp)))
		return;

	/* Invalidate rs_buf to force "stir" (reseed). */
	memset(rs, 0, sizeof(*rs));
}
