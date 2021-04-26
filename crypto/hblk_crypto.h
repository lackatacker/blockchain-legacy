#ifndef HBLK_CRYPTO_H
#define HBLK_CRYPTO_H
#include <stdio.h>
#include <openssl/evp.h>
uint8_t *sha256(int8_t const *s, size_t len,
uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);
int ec_save(EC_KEY *key, char const *folder);
EC_KEY *ec_load(char const *folder);
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg,
size_t msglen, sig_t *sig);
int ec_verify(EC_KEY const *key, uint8_t const *msg,
size_t msglen, sig_t const *sig);
