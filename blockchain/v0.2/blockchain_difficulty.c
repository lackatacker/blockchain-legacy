#include "blockchain.h"
/**
 * blockchain_difficulty - gives a potential difficulty.
 * @blockchain: the blockchain to analyze.
 * Return: the potential difficulty.
 */
uint32_t blockchain_difficulty(blockchain_t const *blockchain)
{
uint8_t block_index;
uint32_t et, eet, newDifficulty = 0;
block_t *tail_block = llist_get_tail(blockchain->chain), *last;
if (tail_block->info.index % DIFFICULTY_ADJUSTMENT_INTERVAL == 0
&& tail_block->info.index != 0)
{
block_index = llist_size(blockchain->chain) - DIFFICULTY_ADJUSTMENT_INTERVAL;
last = llist_get_node_at(blockchain->chain, block_index + 1);
newDifficulty = last->info.difficulty;
eet = DIFFICULTY_ADJUSTMENT_INTERVAL * BLOCK_GENERATION_INTERVAL;
et = tail_block->info.timestamp - last->info.timestamp;
if (et < (eet * 2))
newDifficulty++;
else if (eet > (eet * 2))
newDifficulty--;
return (newDifficulty);
}
return (tail_block->info.difficulty);
}
