# $FreeBSD$

SODIUMDIR?=	${SRCTOP}/sys/contrib/libsodium
SODIUMSRC?=	${SODIUMDIR}/src/libsodium
SODIUMSYS?=	${SRCTOP}/sys/crypto/libsodium
SODIUMTEST?=	${SODIUMDIR}/test

.PATH: ${SODIUMSRC}/crypto_aead
.PATH: ${SODIUMSRC}/crypto_aead/aes256gcm
.PATH: ${SODIUMSRC}/crypto_aead/aes256gcm/aesni
.PATH: ${SODIUMSRC}/crypto_aead/chacha20poly1305
.PATH: ${SODIUMSRC}/crypto_aead/chacha20poly1305/sodium
.PATH: ${SODIUMSRC}/crypto_aead/xchacha20poly1305
.PATH: ${SODIUMSRC}/crypto_aead/xchacha20poly1305/sodium
.PATH: ${SODIUMSRC}/crypto_auth
.PATH: ${SODIUMSRC}/crypto_auth/hmacsha256
.PATH: ${SODIUMSRC}/crypto_auth/hmacsha512
.PATH: ${SODIUMSRC}/crypto_auth/hmacsha512256
.PATH: ${SODIUMSRC}/crypto_box
.PATH: ${SODIUMSRC}/crypto_box/curve25519xchacha20poly1305
.PATH: ${SODIUMSRC}/crypto_box/curve25519xsalsa20poly1305
.PATH: ${SODIUMSRC}/crypto_core
.PATH: ${SODIUMSRC}/crypto_core/ed25519
.PATH: ${SODIUMSRC}/crypto_core/ed25519/ref10
.PATH: ${SODIUMSRC}/crypto_core/ed25519/ref10/fe_25_5
.PATH: ${SODIUMSRC}/crypto_core/ed25519/ref10/fe_51
.PATH: ${SODIUMSRC}/crypto_core/hchacha20
.PATH: ${SODIUMSRC}/crypto_core/hsalsa20
.PATH: ${SODIUMSRC}/crypto_core/hsalsa20/ref2
.PATH: ${SODIUMSRC}/crypto_core/salsa
.PATH: ${SODIUMSRC}/crypto_core/salsa/ref
.PATH: ${SODIUMSRC}/crypto_generichash
.PATH: ${SODIUMSRC}/crypto_generichash/blake2b
.PATH: ${SODIUMSRC}/crypto_generichash/blake2b/ref
.PATH: ${SODIUMSRC}/crypto_hash
.PATH: ${SODIUMSRC}/crypto_hash/sha256
.PATH: ${SODIUMSRC}/crypto_hash/sha256/cp
.PATH: ${SODIUMSRC}/crypto_hash/sha512
.PATH: ${SODIUMSRC}/crypto_hash/sha512/cp
.PATH: ${SODIUMSRC}/crypto_kdf
.PATH: ${SODIUMSRC}/crypto_kdf/blake2b
.PATH: ${SODIUMSRC}/crypto_kx
.PATH: ${SODIUMSRC}/crypto_onetimeauth
.PATH: ${SODIUMSRC}/crypto_onetimeauth/poly1305
.PATH: ${SODIUMSRC}/crypto_onetimeauth/poly1305/donna
.PATH: ${SODIUMSRC}/crypto_onetimeauth/poly1305/sse2
.PATH: ${SODIUMSRC}/crypto_pwhash
.PATH: ${SODIUMSRC}/crypto_pwhash/argon2
.PATH: ${SODIUMSRC}/crypto_pwhash/scryptsalsa208sha256
.PATH: ${SODIUMSRC}/crypto_pwhash/scryptsalsa208sha256/nosse
.PATH: ${SODIUMSRC}/crypto_pwhash/scryptsalsa208sha256/sse
.PATH: ${SODIUMSRC}/crypto_scalarmult
.PATH: ${SODIUMSRC}/crypto_scalarmult/curve25519
.PATH: ${SODIUMSRC}/crypto_scalarmult/curve25519/ref10
.PATH: ${SODIUMSRC}/crypto_scalarmult/curve25519/sandy2x
.PATH: ${SODIUMSRC}/crypto_scalarmult/ed25519
.PATH: ${SODIUMSRC}/crypto_scalarmult/ed25519/ref10
.PATH: ${SODIUMSRC}/crypto_secretbox
.PATH: ${SODIUMSRC}/crypto_secretbox/xchacha20poly1305
.PATH: ${SODIUMSRC}/crypto_secretbox/xsalsa20poly1305
.PATH: ${SODIUMSRC}/crypto_secretstream
.PATH: ${SODIUMSRC}/crypto_secretstream/xchacha20poly1305
.PATH: ${SODIUMSRC}/crypto_shorthash
.PATH: ${SODIUMSRC}/crypto_shorthash/siphash24
.PATH: ${SODIUMSRC}/crypto_shorthash/siphash24/ref
.PATH: ${SODIUMSRC}/crypto_sign
.PATH: ${SODIUMSRC}/crypto_sign/ed25519
.PATH: ${SODIUMSRC}/crypto_sign/ed25519/ref10
.PATH: ${SODIUMSRC}/crypto_stream
.PATH: ${SODIUMSRC}/crypto_stream/chacha20
.PATH: ${SODIUMSRC}/crypto_stream/chacha20/dolbeau
.PATH: ${SODIUMSRC}/crypto_stream/chacha20/ref
.PATH: ${SODIUMSRC}/crypto_stream/salsa20
.PATH: ${SODIUMSRC}/crypto_stream/salsa20/ref
.PATH: ${SODIUMSRC}/crypto_stream/salsa20/xmm6
.PATH: ${SODIUMSRC}/crypto_stream/salsa20/xmm6int
.PATH: ${SODIUMSRC}/crypto_stream/salsa2012
.PATH: ${SODIUMSRC}/crypto_stream/salsa2012/ref
.PATH: ${SODIUMSRC}/crypto_stream/salsa208
.PATH: ${SODIUMSRC}/crypto_stream/salsa208/ref
.PATH: ${SODIUMSRC}/crypto_stream/xchacha20
.PATH: ${SODIUMSRC}/crypto_stream/xsalsa20
.PATH: ${SODIUMSRC}/crypto_verify
.PATH: ${SODIUMSRC}/crypto_verify/sodium
.PATH: ${SODIUMSRC}/include
.PATH: ${SODIUMSRC}/include/sodium
.PATH: ${SODIUMSRC}/include/sodium/private
.PATH: ${SODIUMSRC}/sodium

SRCS+=	aead_chacha20poly1305.c
SRCS+=	aead_xchacha20poly1305.c
SRCS+=	argon2-core.c
SRCS+=	argon2-encoding.c
SRCS+=	argon2-fill-block-ref.c
SRCS+=	argon2.c
# Sodium incorrectly uses const qualification to store a pointer it will
# subsequently write to in the argon2 context struct.  For now, punt on the
# warning.
CWARNFLAGS.argon2.c+= -Wno-cast-qual
SRCS+=	auth_hmacsha256.c
SRCS+=	auth_hmacsha512.c
SRCS+=	auth_hmacsha512256.c
SRCS+=	blake2b-compress-ref.c
SRCS+=	blake2b-long.c
SRCS+=	blake2b-ref.c
SRCS+=	box_curve25519xchacha20poly1305.c
SRCS+=	box_curve25519xsalsa20poly1305.c
SRCS+=	box_seal_curve25519xchacha20poly1305.c
SRCS+=	chacha20_ref.c
SRCS+=	codecs.c
SRCS+=	consts.S
SRCS+=	core_ed25519.c
SRCS+=	core_hchacha20.c
SRCS+=	core_hsalsa20_ref2.c
SRCS+=	core_hsalsa20.c
SRCS+=	core_salsa_ref.c
SRCS+=	core.c
# pthread_lock / unlock wrappers as usual.  This is a noisy warning.
# The unused variable is just sloppy code.
CWARNFLAGS.core.c+= -Wno-thread-safety-analysis -Wno-unused-variable
SRCS+=	crypto_auth.c
SRCS+=	crypto_box_easy.c
SRCS+=	crypto_box_seal.c
SRCS+=	crypto_box.c
SRCS+=	crypto_generichash.c
SRCS+=	crypto_hash.c
SRCS+=	crypto_kdf.c
SRCS+=	crypto_kx.c
SRCS+=	crypto_onetimeauth.c
SRCS+=	crypto_pwhash.c
SRCS+=	crypto_scalarmult.c
SRCS+=	crypto_scrypt-common.c
CWARNFLAGS.crypto_scrypt-common.c+= -Wno-cast-qual
SRCS+=	crypto_secretbox_easy.c
SRCS+=	crypto_secretbox.c
SRCS+=	crypto_shorthash.c
SRCS+=	crypto_sign.c
SRCS+=	crypto_stream.c
SRCS+=	curve25519_sandy2x.c
SRCS+=	ed25519_ref10.c
# Ugly.
CWARNFLAGS.ed25519_ref10.c+=	-Wno-shadow
SRCS+=	fe_frombytes_sandy2x.c
SRCS+=	fe51_invert.c
SRCS+=	fe51_mul.S
SRCS+=	fe51_nsquare.S
SRCS+=	fe51_pack.S
SRCS+=	generichash_blake2.c
SRCS+=	generichash_blake2b.c
SRCS+=	hash_sha256_cp.c
SRCS+=	hash_sha256.c
SRCS+=	hash_sha512_cp.c
SRCS+=	hash_sha512.c
SRCS+=	kdf_blake2b.c
SRCS+=	keypair.c
SRCS+=	ladder_base.S
SRCS+=	ladder.S
SRCS+=	obsolete.c
SRCS+=	onetimeauth_poly1305.c
SRCS+=	open.c
SRCS+=	pbkdf2-sha256.c
SRCS+=	poly1305_donna.c
SRCS+=	pwhash_argon2i.c
SRCS+=	pwhash_argon2id.c
SRCS+=	pwhash_scryptsalsa208sha256_nosse.c
CWARNFLAGS.pwhash_scryptsalsa208sha256_nosse.c+= -Wno-cast-align -Wno-cast-qual
SRCS+=	pwhash_scryptsalsa208sha256_sse.c
CWARNFLAGS.pwhash_scryptsalsa208sha256_sse.c+= -Wno-cast-align
SRCS+=	pwhash_scryptsalsa208sha256.c
SRCS+=	runtime.c
SRCS+=	salsa20_ref.c
SRCS+=	sandy2x.S
SRCS+=	scalarmult_curve25519.c
SRCS+=	scalarmult_ed25519_ref10.c
SRCS+=	scrypt_platform.c
SRCS+=	secretbox_xchacha20poly1305.c
SRCS+=	secretbox_xsalsa20poly1305.c
SRCS+=	secretstream_xchacha20poly1305.c
SRCS+=	shorthash_siphash24_ref.c
SRCS+=	shorthash_siphash24.c
SRCS+=	shorthash_siphashx24_ref.c
SRCS+=	shorthash_siphashx24.c
SRCS+=	sign_ed25519.c
SRCS+=	sign.c
SRCS+=	stream_chacha20.c
SRCS+=	stream_salsa20.c
SRCS+=	stream_salsa2012_ref.c
SRCS+=	stream_salsa2012.c
SRCS+=	stream_salsa208_ref.c
SRCS+=	stream_salsa208.c
SRCS+=	stream_xchacha20.c
SRCS+=	stream_xsalsa20.c
SRCS+=	utils.c
SRCS+=	verify.c
CWARNFLAGS.verify.c+= -Wno-cast-qual
SRCS+=	version.c
SRCS+=	x25519_ref10.c

# M.D.
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "amd64"
SRCS+=	aead_aes256gcm_aesni.c
CFLAGS.aead_aes256gcm_aesni.c+= -msse2 -mssse3 -maes -mpclmul
# For some bogus reason, the canonical definition of the /unaligned/ variants
# of AVX load/store primitives has a 128-bit type pointer as argument, instead
# of plain bytes.  This code uses the unaligned versions.
CWARNFLAGS.aead_aes256gcm_aesni.c+= -Wno-cast-align
SRCS+=	argon2-fill-block-avx2.c
CFLAGS.argon2-fill-block-avx2.c+= -msse2 -mssse3 -msse4.1 -mavx -mavx2
CWARNFLAGS.argon2-fill-block-avx2.c+= -Wno-cast-align
SRCS+=	argon2-fill-block-avx512f.c
CFLAGS.argon2-fill-block-avx512f.c+= -msse2 -mssse3 -msse4.1 -mavx -mavx2 -mavx512f
CWARNFLAGS.argon2-fill-block-avx512f.c+= -Wno-cast-align
SRCS+=	argon2-fill-block-ssse3.c
CFLAGS.argon2-fill-block-ssse3.c+= -msse2 -mssse3
CWARNFLAGS.argon2-fill-block-ssse3.c+= -Wno-cast-align
SRCS+=	blake2b-compress-avx2.c
CFLAGS.blake2b-compress-avx2.c+= -msse2 -mssse3 -msse4.1 -mavx -mavx2
CWARNFLAGS.blake2b-compress-avx2.c+= -Wno-cast-align -Wno-cast-qual
SRCS+=	blake2b-compress-sse41.c
CFLAGS.blake2b-compress-sse41.c+= -msse2 -mssse3 -msse4.1
SRCS+=	blake2b-compress-ssse3.c
CFLAGS.blake2b-compress-ssse3.c+= -msse2 -mssse3
CWARNFLAGS.blake2b-compress-ssse3.c+= -Wno-cast-align -Wno-cast-qual
SRCS+=	chacha20_dolbeau-avx2.c
CFLAGS.chacha20_dolbeau-avx2.c+= -msse2 -mssse3 -msse4.1 -mavx -mavx2
CWARNFLAGS.chacha20_dolbeau-avx2.c+= -Wno-cast-align -Wno-cast-qual
SRCS+=	chacha20_dolbeau-ssse3.c
CFLAGS.chacha20_dolbeau-ssse3.c+= -msse2 -mssse3
CWARNFLAGS.chacha20_dolbeau-ssse3.c+= -Wno-cast-align -Wno-cast-qual
SRCS+=	poly1305_sse2.c
CFLAGS.poly1305_sse2.c+= -msse2
SRCS+=	salsa20_xmm6-asm.S
SRCS+=	salsa20_xmm6.c
SRCS+=	salsa20_xmm6int-avx2.c
CFLAGS.salsa20_xmm6int-avx2.c+= -msse2 -mssse3 -msse4.1 -mavx -mavx2
CWARNFLAGS.salsa20_xmm6int-avx2.c+= -Wno-cast-align -Wno-cast-qual -Wno-shadow
SRCS+=	salsa20_xmm6int-sse2.c
CWARNFLAGS.salsa20_xmm6int-sse2.c+= -Wno-cast-align -Wno-cast-qual -Wno-shadow
.endif

LIB=	sodium
INTERNALLIB=
MAN=	# No manpage; this is internal.
#WARNS?=	6

CFLAGS+=	-I${SODIUMSRC}/include/sodium
CFLAGS+=	-include ${.CURDIR}/config.h

.include <bsd.lib.mk>

# Sodium uses unconditional MSVC pragmas extensively.  Ignore.
CWARNFLAGS+=	-Wno-unknown-pragmas

# Maybe goes away when I update to Clang 10.
CWARNFLAGS+=	-Wno-system-headers

# Sodium often defines inline functions in headers that are not used by all
# includers.  Ignore.
CWARNFLAGS+=	-Wno-unused-function
