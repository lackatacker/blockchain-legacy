#include "blockchain.h"
/**
 * block_hash - hashes info + data
*/
uint8_t *block_hash(block_t const *block, uint8_t
hash_buf[SHA256_DIGEST_LENGTH])
{
if (!block)
return (NULL);
SHA256(&block, block->data.len + sizeof(block->info), hash_buf);
return ((uint8_t *)(hash_buf));
}
