Skip to content
Search or jump to…

Pulls
Issues
Marketplace
Explore
 
@lackatacker 
louizimoncef
/
emsi-blockchain
1
00
Code
Issues
Pull requests
Actions
Projects
Wiki
More
emsi-blockchain/blockchain/v0.1/block_create.c
@louizimoncef
louizimoncef Update block_create.c
Latest commit f029e69 11 days ago
 History
 1 contributor
29 lines (29 sloc)  848 Bytes
  
#include "blockchain.h"
/**
 * block_create - create a block and initialises it
 *@prev: previous  block
 *@data: data to be stored in the block
 *@data_len: length of data
 * Return: a new block structure or NULL
 */
block_t *block_create(block_t const *prev, int8_t const *data,
uint32_t data_len)
{
uint32_t i;
block_t *block = (block_t *) malloc(sizeof(block_t));
if (!prev || !data)
return (NULL);
block->info.index = prev->info.index + 1;
block->info.difficulty = 0;
block->info.nonce = 0;
block->info.timestamp = time(0);
memcpy(block->info.prev_hash, prev->hash, SHA256_DIGEST_LENGTH);
memcpy(block->data.buffer, data, BLOCKCHAIN_DATA_MAX);
if (data_len > (uint32_t)BLOCKCHAIN_DATA_MAX)
block->data.len = BLOCKCHAIN_DATA_MAX;
else
block->data.len = data_len;
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
block->hash[i] = 0;
return (block);
}
© 2021 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About
Loading complete
