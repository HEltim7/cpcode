//蛇形矩阵
#include <stdio.h>
int main()
{
	int n, level, x, y, limit, num = 1, sum = 0, i;
	scanf("%d", &n);
	int matrix[n][n];
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++)
		{
			matrix[x][y] = 0;
		}
	}
	level = (n - 1) / 2;
	x = level;
	y = level;
	matrix[level][level] = num;
	for (i = 2; i < n; i += 2)
	{
		limit = i / 2; //limit
		//right
		for (x++; y >= level - limit; y--)
		{
			num++;
			matrix[y][x] = num;
		}
		//top
		y++;
		for (x--; x >= level - limit; x--)
		{
			num++;
			matrix[y][x] = num;
		}
		//left
		x++;
		for (y++; y <= level + limit; y++)
		{
			num++;
			matrix[y][x] = num;
		}
		//bottom
		y--;
		for (x++; x <= level + limit; x++)
		{
			num++;
			matrix[y][x] = num;
		}
		x--;
	}
	for (y = 0; y < n; y++)
	{
		for (x = 0; x < n; x++)
		{
			printf("%d ", matrix[y][x]);
			if (x == y || x + y == n - 1)
			{
				sum += matrix[y][x];
			}
		}
		printf("\n");
	}
	printf("%d", sum);
	return 0;
}