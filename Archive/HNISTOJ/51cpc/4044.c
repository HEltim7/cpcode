#include "stdio.h"
int main()
{
  long long n, num = 0;
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++)
  {
    int tmp = i;
    while (tmp != 0)
    {
      if (tmp % 10 == 1 || tmp % 10 == 2)
      {
        num++;
      }
      tmp /= 10;
    }
  }
  printf("%d", num % 20123);

  return 0;
}
