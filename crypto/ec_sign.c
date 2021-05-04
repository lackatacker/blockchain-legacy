#include "hblk_crypto.h"
/**
 * ec_sign - Signs a given set of bytes.
 * @key: EC Key pair to sign the message.
 * @msg: characters to verify the signature of.
 * @sig: signature to be checked.
 * @msglen: msgs's length.
 * Return: NULL, or the sig upon success.
 */
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
sig_t *sig)
{
if (key && msg && ECDSA_sign(EC_CURVE, msg, msglen, sig->sig,
(unsigned int *)&(sig->len), (EC_KEY *)key))
return (sig->sig);
return (NULL);
}
