#include <stdio.h>
int main()
{
    int row, column;
    scanf("%d%d", &row, &column);
    int data, max = -32768, max_row = 0, max_column = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &data);
            if (data > max)
            {
                max = data;
                max_row = i;
                max_column = j;
            }
        }
    }
    printf("%d %d %d", max_row, max_column, max);
    return 0;
}