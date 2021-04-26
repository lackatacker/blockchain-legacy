#include "hblk_crypto.h"
uint8_t *sha256(int8_t *s, size_t len, uint8_t digest[SHA256_DIGEST_LENGTH])
{
if (digest == NULL)
return (NULL);
else
{
EVP_MD_CTX *mdctx = EVP_MD_CTX_new();
const EVP_MD *md = EVP_sha256();
unsigned char md_value[EVP_MAX_MD_SIZE];
unsigned int md_len, i;
EVP_DigestInit_ex(mdctx, md, NULL);
EVP_DigestUpdate(mdctx, s, strlen(s));
EVP_DigestFinal_ex(mdctx, md_value, &md_len);
EVP_MD_CTX_free(mdctx);
int8_t *md_val = (int8_t *)md_value;
return (md_value);
}
}
