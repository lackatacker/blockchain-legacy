#include "blockchain.h"
void blockchain_destroy(blockchain_t *blockchain)
{
if (!blockchain)
		return;

	llist_destroy(blockchain->chain, 1, (node_dtor_t)free);

	free(blockchain);
}
