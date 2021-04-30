#include "blockchain.h"
uint8_t *block_hash(block_t const *block, uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
  if(!block)
    return (NULL);
  SHA256((unsigned char *)block, sizeof(block->data.len)+block->data.len+sizeof(block->info), hash_buf);
  return (uint8_t *)(hash_buf);
}
