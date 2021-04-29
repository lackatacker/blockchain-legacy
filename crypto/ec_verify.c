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
  if (!key | !msg | !sig | !ec_verify(key, msg, msglen, sig))
    return (0);
  return (1);
}
