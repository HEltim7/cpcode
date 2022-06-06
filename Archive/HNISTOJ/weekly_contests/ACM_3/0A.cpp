#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int a, b, len1, len2, index, i, j;
	char str1[11], str2[11], c[11];
	while (scanf("%s %s", str1, str2) != EOF)
	{
		len1 = strlen(str1);
		len2 = strlen(str2);
		index = 0;
		for (i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
		{
			int sum = str1[i] - '0' + str2[j] - '0';
			if (sum > 9)
			{
				sum -= 10;
			}
			c[index++] = sum + '0';
		}
		while (i >= 0)
		{
			c[index++] = str1[i];
			i--;
		}
		while (j >= 0)
		{
			c[index++] = str2[j];
			j--;
		}
		index = index - 1;
		while (c[index] == '0' && index > 0)
		{
			index--;
		}
		printf("%d ", atoi(str1) + atoi(str2));
		for (i = index; i >= 0; i--)
		{
			printf("%c", c[i]);
		}
		printf("\n");
	}
	return 0;
}