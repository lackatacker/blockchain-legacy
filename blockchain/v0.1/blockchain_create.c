#include "blockchain.h"
blockchain_t *blockchain_create(void)
{
  block_t *genesisBlock = malloc(sizeof(block_t)), *gen = BLOCK_GENESIS;
  blockchain_t *new_blockchain = malloc(sizeof(blockchain_t));
  new_blockchain->chain = llist_create(MT_SUPPORT_TRUE);
  memcpy(&genesisBlock, gen, sizeof(block_t));
  if(!llist_add_node(new_blockchain->chain,(block_t *) &genesisBlock,ADD_NODE_FRONT))
    return (new_blockchain);
  return (NULL);
}
