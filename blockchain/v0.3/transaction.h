#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "blockchain.h"
#include <stdint.h>
typedef struct tx_out_s
{
  uint32_t    amount;
  uint8_t     pub[EC_PUB_LEN];
  uint8_t     hash[SHA256_DIGEST_LENGTH];
} tx_out_t;

typedef struct tx_in_s
{
  uint8_t     block_hash[SHA256_DIGEST_LENGTH];
  uint8_t     tx_id[SHA256_DIGEST_LENGTH];
  uint8_t     tx_out_hash[SHA256_DIGEST_LENGTH];
  sig_t       sig;
} tx_in_t;
typedef struct transaction_s
{
  uint8_t     id[SHA256_DIGEST_LENGTH];
  llist_t     *inputs;
  llist_t     *outputs;

#define COINBASE_AMOUNT    50
tx_out_t *tx_out_create(uint32_t amount, uint8_t const pub[EC_PUB_LEN]);
#endif
