#include <stdio.h>
#include <stdint.h>

int main()
{
  uint32_t i = 1, j = 2, k = 3, l = 4;
  uint32_t n = i << 24 | j << 16 | k << 8 | l;
  printf("n = %x\n", n);
  n = (i << 24) + (j << 16) + (k << 8) + l;
  printf("n = %x\n", n);

  uint64_t i64 = 1, j64 = 2, k64 = 3, l64 = 4;
  uint64_t n64 = i64 << 48 | j64 << 32 | k64 << 16 | l;
  printf("n64 = %lx\n", n64);
  n64 = (i64 << 48) + (j64 << 32) + (k64 << 16) + l;
  printf("n64 = %lx\n", n64);
  
  return 0;
}
