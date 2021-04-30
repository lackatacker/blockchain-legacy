#include "blockchain.h"
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
{
block_t *block = malloc(sizeof(block_t));
if(!data || !prev)
return (NULL);
block->info.index = prev->info.index + 1;
block->info.difficulty = 0;
block->info.nonce = 0;
block->info.timestamp = time(NULL);
memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
if(data_len > BLOCKCHAIN_DATA_MAX)
{
block->data.len = BLOCKCHAIN_DATA_MAX;
memcpy(block->data.buffer, data, BLOCKCHAIN_DATA_MAX);
}
else
{
block->data.length = data_len;
memcpy(block->data.buffer, data, data_len);
}
memset(block->hash, 0, SHA256_DIGEST_LENGTH);
return(block);
}
