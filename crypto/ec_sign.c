#include "hblk_crypto.h"
/**
 * @ec_sign - Signs a given set of bytes, using a given EC_KEY public key
 *
 * test_ec_sign - Test the ec_sign function
 *
 * @key: Pointer to the EC Key pair to use to sign the message
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
sig_t *sig)
{
if (!key || !msg)
return (NULL);
if (ECDSA_sign(EC_CURVE, msg, msglen, sig->sig, (unsigned int *)&(sig->len)
, (EC_KEY *)key))
return (sig->sig);
return (NULL);
}
