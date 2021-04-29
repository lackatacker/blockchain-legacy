#include "hblk_crypto.h"

/**
 * ec_sign - a function that signs a given set of bytes
 * @key: points to the EC_KEY
 * @msg:  points to the msg
 * @msglen: is the length of msg
 * @sig: holds the address at which to store the signature
 * Return: uint8_t* a pointer to digest or null on failure
*/
uint8_t *ec_sign(EC_KEY const *key, uint8_t const *msg, size_t msglen,
		 sig_t *sig)
{
	unsigned char hash[SHA256_DIGEST_LENGTH];

	if (!key || !msg || !sig)
		return (NULL);
	if (!EC_KEY_check_key(key))
		return (NULL);
	if (!SHA256(msg, msglen, hash))
		return (NULL);
	sig->len = ECDSA_size(key);
	if (!sig->len)
		return (NULL);
	if (!ECDSA_sign(EC_CURVE, hash, SHA256_DIGEST_LENGTH, sig->sig,
			(unsigned int *)&(sig->len), (EC_KEY *)key))
		return (NULL);
	return (sig->sig);
}
