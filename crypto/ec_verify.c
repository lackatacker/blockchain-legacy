#include "hblk_crypto.h"
/**
 * test_ec_sign - Test the ec_sign function
 * @ a signature is a crypted hash ;)
 * @key: Pointer to the EC Key pair to use to sign the message
 * @msg: the hash that the sig should match
 * @msglen: the message length
 * @sig: the signature that should match the message once decrypted
 * @ec-verify: it verifies if a given msg matches a hash with a given key 
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int ec_verify(EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t const *sig)
{
unsigned char hash[SHA256_DIGEST_LENGTH];
if (!key || !msg || !sig || !(sig->len) || !msglen)
return (0);
if (ECDSA_verify(0, hash, SHA256_DIGEST_LENGTH, msg, msglen,
(EC_KEY *)key))
return (1);
return (0);
}
