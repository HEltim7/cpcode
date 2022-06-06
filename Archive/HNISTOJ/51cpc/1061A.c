#include <stdio.h>
#include <string.h>
int main()
{
	char str[2048];
	scanf("%[^\n]", str);
	int num = 0, size = strlen(str), judge = 0;
	for (int i = 0; i < size; i++)
	{
		char c = str[i];
		if (judge && c == ' ')
		{
			num += 1;
		}
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ',')
		{
			judge = 1;
		}
		else
		{
			judge = 0;
		}
	}
	printf("%d", num + 1);
	return 0;
}