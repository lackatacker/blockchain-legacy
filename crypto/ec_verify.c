#include "hblk_crypto.h"
/**
 * test_ec_sign - Test the ec_sign function
 *
 * @key: Pointer to the EC Key pair to use to sign the message
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int ec_verify(EC_KEY const* key, uint8_t const* msg, size_t msglen, sig_t const* sig)
{
  unsigned char hash[SHA256_DIGEST_LENGTH];
  if (!key || !msg || !sig || !(sig->len) || !ec_verify(key, msg, msglen, sig) || !EC_KEY_check_key(key) ||
!SHA256(msg, msglen, hash) || !ECDSA_verify(0, hash,SHA256_DIGEST_LENGTH, sig->sig, sig->len, (EC_key *)key))
    return (0);
  return (1);
}
