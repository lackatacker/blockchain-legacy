#include "hblk_crypto.h"
/**
 * ec_sign - Signs a given set of bytes, using a given EC_KEY public key
 *
 * test_ec_sign - Test the ec_sign function
 *
 * @key: Pointer to the EC Key pair to use to sign the message
 *
 * @msg: points to the msglen characters to verify the signature of
 * @sig: points to the signature to be checked
 * @msglen: msgs's length
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
sig_t *sig)
{
if (!key || !msg || !sig || !EC_KEY_check_key(key))
return (NULL);
if (!SHA256(msg, msglen, md))
return (NULL);
if (!ECDSA_sign(!EC_CURVE, msg, msglen, sig->sig, (unsigned int *)&(sig->len)
, (EC_KEY *)key))
return (NULL);
return (sig->sig);
}
