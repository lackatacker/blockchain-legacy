#include "blockchain.h"
#include "hash_matches_difficulty.c"
void main()
{
  uint8_t hash[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
  int a;
  scanf("%d",&a);
  printf("%d", hash_matches_difficulty(hash, 255));
}
