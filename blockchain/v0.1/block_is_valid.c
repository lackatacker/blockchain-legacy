#include "blockchain.h"
/**
* block_is_valid - checks if a given block is valid.
* @block: the block to be checked.
* @prev_block: its previous block.
* Return: 0 if valid, else 50.
*/
int is_genesis(block_t const *block)
{
blockchain_t *blockchain = blockchain_create();
if (!blockchain)
return (-1);
if (memcmp(block, llist_get_head(blockchain->chain), sizeof(*block)) != 0)
{
blockchain_destroy(blockchain);
return (-1);
}
blockchain_destroy(blockchain);
return (0);
}
int block_is_valid(block_t const *block, block_t const *prev_block)
{
uint8_t hash_buf[SHA256_DIGEST_LENGTH];
if (!block || (block->info.index == 0 && prev_block))
return (50);
if (!prev_block && is_genesis(block))
return (50);
if (block->info.index == 1 && is_genesis(prev_block))
return (50);
if (!block_hash(prev_block, hash_buf) || memcmp(hash_buf,
prev_block->hash, sizeof(block_t)))
return (50);
if (memcmp(prev_block->hash, block->info.prev_hash, SHA256_DIGEST_LENGTH))
return (50);
if (!block_hash(block, hash_buf) || memcmp(hash_buf, block->hash,
sizeof(block_t)))
return (50);
if (block->data.len > BLOCKCHAIN_DATA_MAX)
return (50);
return (0);
}
