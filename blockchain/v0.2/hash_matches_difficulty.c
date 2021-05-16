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
int i, cpt=0;
for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
if (!hash[i])
cpt+=8;
for(i = 0; i<8; i++)
if(hash[i] >> i == 0)
cpt+=i;
if(cpt < difficulty)
return 0;
return 1;
}
