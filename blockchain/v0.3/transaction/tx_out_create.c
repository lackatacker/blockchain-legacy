#include "transaction.h"
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
  tx_out_t *tx_out = malloc(sizeof(tx_out_t));
if (!amount || !pub)
  return (NULL);
if (!memcpy(&tx_out->amount, &amount, sizeof(amount)) ||
   !memcpy(&tx_out->pub, &pub, EC_PUB_LEN) ||
   !sha256((const int8_t *)tx_out, SHA256_DIGEST_LEN, tx_out->hash))
  return (NULL);
return (tx_out);
}
