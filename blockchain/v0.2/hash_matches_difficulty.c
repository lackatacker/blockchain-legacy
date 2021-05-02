#include "blockchain.h"
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
uint32_t difficulty);
{
uint8_t i;
if (!hash)
return (0);
for (i=0; i<difficulty ; i++)
if (hash[i])
return (0);
return (1); 
}
