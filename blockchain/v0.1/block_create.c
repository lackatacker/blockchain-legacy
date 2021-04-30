#include "blockchain.h"
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
{
int mylen = (((BLOCKCHAIN_DATA_MAX) < (data_len)) ?
(BLOCKCHAIN_DATA_MAX) : (data_len));
block_t *block = malloc(sizeof(block_t));
if(!data || !prev)
return (NULL);
block->info.index = prev->info.index + 1;
block->info.difficulty = block->info.nonce = 0;
block->info.timestamp = time(NULL);
block->data.len= mylen;
(BLOCKCHAIN_DATA_MAX) : (prev->data.len));
memcpy(block->info.prev_hash, prev->hash, mylen);
memcpy(block->data.buffer , data, BLOCKCHAIN_DATA_MAX);
memset(block->hash, 0, SHA256_DIGEST_LENGTH);
return(block);
}
