#include "blockchain.h"
/**
* hash_matches_difficulty - checks if hash matches difficulty
* @hash: hash to check
* @difficulty: difficulty of a block
* Return: 1 if hash matches difficulty, otherwise 0
*/
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty)
{
uint8_t i = 0, cpt=0;
int bit = 7;
{
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
for (bit = 7; bit >= 0; bit--)
{
if (hash[i] & 1 << bit)
break;
else
cpt++;
}
}
if (cpt < difficulty)
return (0);
return (1);
}
