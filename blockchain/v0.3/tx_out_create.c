<<<<<<< HEAD
=======
#include "transaction.h"
>>>>>>> 7dc03f433cf99c8956f0f0aa300d2dc3180d826e
#include "blockchain.h"
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN])
{
  tx_out_t *tr;

  if (!pub)
    return (NULL);
  tr = calloc(1, sizeof(*tr));
  if (!tr)
    return (NULL);
  tr->amount = amount;
  memcpy(tr->pub, pub, EC_PUB_LEN);
  if (!sha256((const int8_t *)tr, TX_OUT_HASH_LEN, tr->hash))
    {
      free(tr);
      return (NULL);
    }
  return (tr);
}
