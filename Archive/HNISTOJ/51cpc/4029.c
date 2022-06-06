//级数求和
#include <stdio.h>
int main()
{
	double sn = 0;
	int n = 1;
	int k;
	scanf("%d", &k);
	while (!(sn > k))
	{
		sn += 1. / n;
		n++;
	}
	printf("%d", n - 1);
	return 0;
}