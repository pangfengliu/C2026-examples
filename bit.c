#include <stdio.h>
#include <stdint.h>

uint16_t get(uint64_t n64, int i)
{
  return (n64 >> (48 - i * 16)) & (((uint64_t)1 << 16) - 1);
}

int main()
{
  uint32_t i = 1, j = 2, k = 3, l = 4;
  uint32_t n = i << 24 | j << 16 | k << 8 | l;
  printf("n = %x\n", n);
  n = (i << 24) + (j << 16) + (k << 8) + l;
  printf("n = %x\n", n);

  uint32_t mask = (1 << 8) - 1;
  printf("%x\n", n >> 24 & mask);
  printf("%x\n", n >> 16 & mask);
  printf("%x\n", n >> 8 & mask);
  printf("%x\n", n >> 0 & mask);
	
  uint64_t i64 = 1, j64 = 2, k64 = 3, l64 = 4;
  uint64_t n64 = i64 << 48 | j64 << 32 | k64 << 16 | l;
  printf("n64 = %lx\n", n64);
  n64 = (i64 << 48) + (j64 << 32) + (k64 << 16) + l;
  printf("n64 = %lx\n", n64);

  uint64_t mask64 = ((uint64_t)1 << 16) - 1;
  printf("%lx\n", n64 >> 48 & mask64);
  printf("%lx\n", n64 >> 32 & mask64);
  printf("%lx\n", n64 >> 16 & mask64);
  printf("%lx\n", n64 >> 0 & mask64);

  printf("use get\n");
  for (int i = 0; i < 4; i++)
    printf("%x\n", get(n64, i));
  
  return 0;
}
