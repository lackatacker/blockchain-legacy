#include "blockchain.h"
llist_t *deserialize_block(FILE* f, uint32_t size, uint8_t endianness)
{
size_t i=0;
  block_t *block;
llist_t *list = llist_create(MT_SUPPORT_TRUE);
if (!list || !f || !size)
return (NULL);
for(i=0; i < size ; i++)
{
block = (block_t *)malloc(sizeof(block_t));
fread(&block->info, sizeof(block->info), 1, f);
fread(&block->data.buffer, sizeof(block->data.buffer), 1, f);
fread(&block->hash, SHA256_DIGEST_LENGTH, 1, f);
if(endianness)
{
_swap_endian(&block->info.difficulty, sizeof(block->info.difficulty));
_swap_endian(&block->info.index, sizeof(block->info.index));
_swap_endian(&block->info.nonce, sizeof(block->info.nonce));
_swap_endian(&block->info.timestamp, sizeof(block->info.timestamp));
}
}
return (list);
}
blockchain_t *blockchain_deserialize(char const *path)
{
blockchain_t *blockchain = (blockchain_t *)malloc(sizeof(blockchain_t));
uint8_t endianness, size=0;
FILE *f;
uint8_t i;
char buffer[500];
blockchain->chain = llist_create(MT_SUPPORT_TRUE);
f = fopen(path, "rb");
if(!path || !f)
return (fclose(f),NULL);
i = fread(&buffer, 4, 1, f);
if (i!=4 || !strcmp(buffer, HBLK_MAGIC))
return (fclose(f),NULL);
i = fread(&buffer, 3, 1, f);
if (i!=3 || !strcmp(buffer, HBLK_VERSION))
return (fclose(f),NULL);
fread(&endianness, 1, 1, f);
if (endianness != 1 || i!=1)
return (fclose(f),NULL);
endianness = endianness != _get_endianness();
i = fread(&size, 4, 1, f);
if(i!=4)
return (fclose(f),NULL);
if(endianness)
_swap_endian(&size, sizeof(size));
blockchain->chain = deserialize_block(f, size, endianness);
return(fclose(f), blockchain);
}
