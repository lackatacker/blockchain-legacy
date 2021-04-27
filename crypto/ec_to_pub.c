#include "hblk_crypto.h"

uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
if (!key)
return (NULL);
const EC_GROUP *group = EC_KEY_get0_group(key);
const EC_POINT *point = EC_KEY_get0_public_key(key);
if (EC_POINT_point2octet(group, point, POINT_CONVERSION_UNCOMPRESSED,
pub, EC_PUB_LEN, NULL))
return (pub);
return (NULL);
}
