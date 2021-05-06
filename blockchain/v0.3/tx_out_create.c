#include "transaction.h"
#include "blockchain.h"
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
  tx_out_t *tx_out = (tx_out_t *)malloc tx_out_t(sizeof(tx_out_t));
if (!amount || !pub)
  return (NULL);
if (!memcpy((uint32_t)tx_out->amount, amount, sizeof(amount)) ||
   !memcpy((uitn32_t)tx_out->pub, pub, sizeof(pub)))
  return (NULL);
return (tx_out);
}
