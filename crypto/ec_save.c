#include "hblk_crypto.h"
int ec_save(EC_KEY *key, char const *folder)
{
char buf[1000];
FILE *fp;
if (!key || !folder)
return (0);
mkdir(folder, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
sprintf(buf, "%s%s", folder, PUBLIC_FILENAME);
fp = fopen(buf, "w");
if (!fp)
return (0);
if (!PEM_write_PUBKEY(fp, key))
return (0);
fpclose();
sprintf(buf, "%s%s", folder, PRIVATE_FILENAME);
fp = fopen(buf, "w");
if (!fp)
return (0);
if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
return (0);
fpclose();
return (1);
}
