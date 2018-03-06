#include<stdio.h>

typedef unsigned int Word;

Word reverseBits(Word w)
{
  Word w1;
  for (int i = 0; i < 32; ++i) {
    w1 = w1 << 1;
    w1 = w1 | (w & 1);
    w = w >> 1;
  }
  return w1;
}

// testing
int main(void)
{
   Word w1 = 0x01234567;
   //0000 => 0000 = 0
   //0001 => 1000 = 8
   //0010 => 0100 = 4
   //0011 => 1100 = C
   //0100 => 0010 = 2
   //0101 => 1010 = A
   //0110 => 0110 = 6
   //0111 => 1110 = E
   assert(reverseBits(w1) == 0xE6A2C480);
   printf("All tests passed!");
   return 0;
}
