#include "hblk_crypto.h"
/**
 * ec_verify - Verifies a given set of bytes, using a given EC_KEY private key
 * @key: EC key pair already generated
 * @msg: message to be signed
 * @msglen: length of that message
 * @sig: pointer to save the signature into
 * Return: 1 if sucess, 0 if failure
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen, 
sig_t const *sig)
{
unsigned char hash[SHA256_DIGEST_LENGTH];
if (!key || !msg || !sig || !(sig->len) || !msglen)
return (0);
if (ECDSA_verify(0, hash, SHA256_DIGEST_LENGTH, msg, msglen,
(EC_KEY *)key))
return (1);
return (0);
}
