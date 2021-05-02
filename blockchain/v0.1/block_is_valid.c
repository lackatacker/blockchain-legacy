#include "blockchain.h"
int block_is_valid(block_t const *block, block_t const *prev_block)
/**
* block_is_valid - returns 0 if the block is valid, 50 otherwise.
*/
{
block_t genesis = BLOCK_GENESIS_INIT;
uint8_t hash_buf[SHA256_DIGEST_LENGTH];
if (!block || (block->info.index == 0 && prev_block))
return (50);
if (!prev_block && memcmp(block, &genesis, sizeof(genesis)))
return (50);
if (block->info.index == 1 && memcmp(prev_block, &genesis, sizeof(genesis)))
return (50);
if (!block_hash(block_prev, hash_buf) || memcmp(hash_buf, prev_block->hash))
return (50);
if (memcmp(prev_block->hash, block->info.prev_hash, SHA256_DIGEST_LENGTH))
return (50);
if (!block_hash(block, hash_buf) || memcmp(hash_buf, block->hash))
return (50);
if (block->data.length > BLOCKCHAIN_DATA_MAX)
return (50);
return (0);
}
