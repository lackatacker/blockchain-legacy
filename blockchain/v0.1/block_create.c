#include "blockchain.h"
block_t *block_create(block_t const *prev, int8_t const *data, uint32_t data_len)
{
block_t *block = NULL;
size_t mylen = 0;
if (!prev || !data )
return (NULL);
mylen = (((BLOCKCHAIN_DATA_MAX) < (data_len)) ?
(BLOCKCHAIN_DATA_MAX) : (data_len));
block = (block_t *) malloc( sizeof(block_t));
block->info.index = prev->info.index + 1;
block->info.difficulty = 0;
block->info.nonce = 0;
block->info.timestamp = time(0);
block->data.len= mylen;
memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
memcpy(block->data.buffer , data, mylen);
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
block->hash[i] = 0;
return(block);
}
