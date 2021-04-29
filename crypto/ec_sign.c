#include "hblk_crypto.h"
/**
 * @ec_sign: used to sign a given msg
 * 
 * test_ec_sign - Test the ec_sign function
 * 
 * @key: Pointer to the EC Key pair to use to sign the message
 * 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t *sig)
{
  if(!key || !msg || !ECDSA_sign(0, msg, msglen, sig->sig,
				 (unsigned int *)&(sig->len), (EC_KEY *)key))
    return (NULL);
  return sig->sig;
}
