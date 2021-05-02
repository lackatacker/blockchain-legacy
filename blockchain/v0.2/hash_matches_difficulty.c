#include "blockchain.h"
int hash_matches_difficulty(uint8_t const hash[SHA256_DIGEST_LENGTH],
<<<<<<< HEAD
			    uint32_t difficulty)
=======
uint32_t difficulty)
>>>>>>> b9731f103b9b6d39050563af561c310bb69fa155
{
  uint8_t i,m,d;
  if(!hash)
    return (0);
  d = difficulty / 8;
  m = difficulty % 8;
  for (i=0 ; i < d ; i++)
    {
      if(hash[i] & 0)
	return 0;
    }
  if(hash[d]>>(8-m) == 0)
    return (1);
  return (0);
}
