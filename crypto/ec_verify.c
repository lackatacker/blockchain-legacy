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
  if (!key || !msg || !sig || !(sig->len) || !ec_verify(key, msg, msglen, sig) ||!SHA256(msg, msglen, hash))
    return (0);
  if (ECDSA_verify(0, hash, SHA256_DIGEST_LENGTH, sig->sig, sig->len,
				(EC_KEY *)key))
    return (1);
  return (0);
}
