#include <stdio.h>

int main()
{
  int i, j = 10;
  int *ptr = &i;
  int **ptrptr = &ptr;
  printf("%p %p %p\n", &i, &ptr, ptr);

  scanf("%d", ptr);
  printf("%d\n", i);

  ptr = &j;
  scanf("%d", ptr);
  printf("%d %d\n", i, j);

  int k;
  k = (*ptr)++;
  printf("%d %d\n", i, j);

  int a[4] = {0};
  ptr = &a[1];
  for (int i = 1; i < 3; i++, ptr++)
    scanf("%d", ptr);

  ptr = a;
  for (int i = 0; i < 4; i++)
    printf("%d\n", *ptr++);

  
  return 0;
}
