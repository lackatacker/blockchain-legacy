#include "hblk_crypto.h"
/**
 * ec_sign - Signs a given set of bytes, using a given EC_KEY public key
 * test_ec_sign - Test the ec_sign function
 * @key: Pointer to the EC Key pair to use to sign the message
 * @msg: points to the msglen characters to verify the signature of
 * @sig: points to the signature to be checked
 * @msglen: msgs's length
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
uint8_t *ec_sign(
	EC_KEY const *key, uint8_t const *msg, size_t msglen, sig_t *sig)
{
	unsigned int len = 0;

	if (key && msg && msglen)
	{
		memset(sig->sig, 0, sizeof(sig->sig) / sizeof(*sig->sig));
		if (ECDSA_sign(0, msg, msglen, sig->sig, &len, (EC_KEY *)key))
		{
			sig->len = len;
			return (sig->sig);
		}
		sig->len = 0;
	}
	return (NULL);
}
