#include <stdio.h>
#include <stdint.h>

int main()
{
  uint32_t i = 1, j = 2, k = 3, l = 4;
  uint32_t n = i << 24 | j << 16 | k << 8 | l;
  printf("n = %x\n", n);
  return 0;
}
