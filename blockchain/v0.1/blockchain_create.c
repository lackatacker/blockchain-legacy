#include "blockchain.h"
blockchain_t *blockchain_create(void)
{
  blockchain_t *new_blockchain = malloc(sizeof(blockchain_t));
  new_blockchain->chain = llist_create(MT_SUPPORT_TRUE);
  block_t genesisBlock = GENESIS_BLOCK;
  if(!llist_add_node(new_blockchain->chain,(block_t *) &genesisBlock,ADD_NODE_FRONT))
    return (new_blockchain);
  return (NULL);
}
