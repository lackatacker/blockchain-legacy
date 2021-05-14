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
uint8_t i, modulo, division;
division = difficulty / 8;
modulo = difficulty % 8;
for (i = 0 ; i < division ; i++)
if (hash[i] != 0)
return (0);
if ((hash[division] >> (8 - modulo)) == 0)
return (1);
return (0);
}
