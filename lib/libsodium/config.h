#pragma once

#define	PACKAGE_NAME		"libsodium"
#define	PACKAGE_TARNAME		"libsodium"
#define	PACKAGE_VERSION		"1.0.16"
#define	PACKAGE_STRING		"libsodium\ 1.0.16"
#define	PACKAGE_BUGREPORT	"https://github.com/jedisct1/libsodium/issues"
#define	PACKAGE_URL		"https://github.com/jedisct1/libsodium"
#define	PACKAGE			"libsodium"
#define	VERSION			"1.0.16"
#define	HAVE_PTHREAD_PRIO_INHERIT 1
#define	HAVE_PTHREAD		1
#define	STDC_HEADERS		1
#define	HAVE_SYS_TYPES_H	1
#define	HAVE_SYS_STAT_H		1
#define	HAVE_STDLIB_H		1
#define	HAVE_STRING_H		1
#define	HAVE_MEMORY_H		1
#define	HAVE_STRINGS_H		1
#define	HAVE_INTTYPES_H		1
#define	HAVE_STDINT_H		1
#define	HAVE_UNISTD_H		1
#define	__EXTENSIONS__		1
#define	_ALL_SOURCE		1
#define	_GNU_SOURCE		1
#define	_POSIX_PTHREAD_SEMANTICS 1
#define	_TANDEM_SOURCE		1
#define	HAVE_C_VARARRAYS	1
#define	HAVE_CATCHABLE_SEGV	1
#define	HAVE_CATCHABLE_ABRT	1
#define	TLS			_Thread_local
#define	HAVE_DLFCN_H		1
#define	LT_OBJDIR		".libs/"
#define	HAVE_SYS_MMAN_H		1
#define	HAVE_INLINE_ASM		1
#define	ASM_HIDE_SYMBOL		.hidden
#define	HAVE_WEAK_SYMBOLS	1
#define	HAVE_ATOMIC_OPS		1
#define	HAVE_ALLOCA		1
#define	HAVE_ARC4RANDOM		1
#define	HAVE_ARC4RANDOM_BUF	1
#define	HAVE_MMAP		1
#define	HAVE_MLOCK		1
#define	HAVE_MADVISE		1
#define	HAVE_MPROTECT		1
#define	HAVE_MEMSET_S		1
#define	HAVE_EXPLICIT_BZERO	1
#define	HAVE_NANOSLEEP		1
#define	HAVE_POSIX_MEMALIGN	1
#define	HAVE_GETPID		1
#define	CONFIGURED		1

/* M.D. */
#if defined(__amd64__) || defined(__i386__)
#define	HAVE_CPUID		1
#define	HAVE_MMINTRIN_H		1
#define	HAVE_EMMINTRIN_H	1
#define	HAVE_PMMINTRIN_H	1
#define	HAVE_TMMINTRIN_H	1
#define	HAVE_SMMINTRIN_H	1
#define	HAVE_AVXINTRIN_H	1
#define	HAVE_AVX2INTRIN_H	1
#define	HAVE_AVX512FINTRIN_H	1
#define	HAVE_WMMINTRIN_H	1
#define	HAVE_RDRAND		1
#define	HAVE_AVX_ASM		1
#endif

#if defined(__amd64__)
#define	HAVE_AMD64_ASM		1
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define	NATIVE_LITTLE_ENDIAN	1
#else
#define	NATIVE_LITTLE_ENDIAN	0
#endif

#if defined(__SIZEOF_INT128__) && NATIVE_LITTLE_ENDIAN
#define	HAVE_TI_MODE		1
#endif

/* Does not actually seem to be used by sources. */
/* #undef CPU_UNALIGNED_ACCESS */
