#include "blockchain.h"
void block_mine(block_t *block)
{
uint8_t hash_buff[SHA256_DIGEST_LENGTH];
if(!block)
return (NULL);
if(!hash_matches_difficulty(block->hash, block->info.difficulty))
while(!hash_matches_difficulty(buff_hash, block->info.difficulty))
{
block->info.nonce++;
block_hash(block, hash_buff);
}
memcpy(block->hash, hash_buff, SHA256_DIGEST_LENGTH);
}
