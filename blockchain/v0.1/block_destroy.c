#include "blockchain.h"
/*
* block_destroy - frees the block.
*/
void block_destroy(block_t *block)
{
free(block);
}
