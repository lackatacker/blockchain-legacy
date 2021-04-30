#include "blockchain.h"
#include "llist.h"
blockchain_t *blockchain_create(void)
{
  blockchain_t *new_blockchain;
  new_blockchain->chain = llist_create(MT_SUPPORT_TRUE);
  if(llist_add_node(new_blockchain->chain,GENESIS_BLOCK,ADD_NODE_FRONT))
    return (new_blockchain);
  return (NULL);
}
