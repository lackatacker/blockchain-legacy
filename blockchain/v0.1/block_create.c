#include "blockchain.h"
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
{
int mylen = (((BLOCKCHAIN_DATA_MAX) < (data_len)) ?
(BLOCKCHAIN_DATA_MAX) : (data_len));
block_t *block;
if (!prev)
return (NULL);
block = (block_t *) malloc( sizeof(block_t));
if(!data)
return (NULL);
block->info.index = prev->info.index + 1;
block->info.difficulty = 0;
block->info.nonce = 0;
block->info.timestamp = time(NULL);
block->data.len= mylen;
memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
memcpy(block->data.buffer , data, mylen);
return(block);
}
