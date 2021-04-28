#include "hblk_crypto.h"
/**
 * this func stores pub/priv keys from eckey given
 * @ec_save - save ec private aand public keys in PEM files
 * @key: EC_key
 * @folder: destination folder
 * Return: 1 succes 0 failed
 */
int ec_save(EC_KEY *key, char const *folder)
{
char buf[1000];
FILE *fp;
if (!key || !folder)
return (0);
mkdir(folder, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
sprintf(buf, "%s/%s", folder, PUB_FILENAME);
fp = fopen(buf, "w");
if (!fp)
return (0);
if (!PEM_write_EC_PUBKEY(fp, key))
return (0);
fclose(fp);
sprintf(buf, "%s/%s", folder, PRI_FILENAME);
fp = fopen(buf, "w");
if (!fp)
return (0);
if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
return (0);
fclose(fp);
return (1);
}
