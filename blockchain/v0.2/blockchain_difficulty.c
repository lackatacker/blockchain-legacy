#include "blockchain.h"
/**
 * blockchain_difficulty - gives a potential difficulty.
 * @blockchain: the blockchain to analyze.
 * Return: the potential difficulty.
 */
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
uint8_t block_index;
uint32_t et, eetime;
block_t *tail_block = llist_get_tail(blockchain->chain);
block_t *last_modified_block;
if (tail_block->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL == 0
&& tail_block->info.index != 0)
{
block_index = llist_size(blockchain->chain) - DIFFICULTY_ADJUSTMENT_INTERVAL + 1;
last_modified_block = llist_get_node_at(blockchain->chain, block_index);
eet = block_index *BLOCK_GENERATION_INTERVAL;
et = tail_block->info.timestamp -
last_modified_block->info.timestamp;
if (elapsed_time < eet * 2)
tail_block->info.difficulty++;
else if (eet > eet * 2)
tail_block->info.difficulty--;
}
return (tail_block->info.difficulty);
}
