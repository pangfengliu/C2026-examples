#include <stdio.h>

int main()
{
    int a, b;
    int r = scanf("%d%d", &a, &b);
    printf("%d %d %d\n", a, b, r);

    while (scanf("%d", &a) != EOF)
      printf("%d\n", a);
	
    return 0;
}
