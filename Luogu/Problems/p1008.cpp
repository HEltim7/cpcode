#include <iostream>
using namespace std;
int number[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
bool num_used[10], flag;

int main()
{
    //百位小于4
    for (int i = 1; i < 4; i++)
    {

        for (int j = 1; j <= 9; j++)
        {
            if (j == i)
            {
                j++;
            }
            for (int k = 1; k <= 9; k++)
            {
                if (k == j || k == i)
                    k++;
                if (k == j || k == i)
                    k++;
                num_used[i] = 1;
                num_used[j] = 1;
                num_used[k] = 1;
                int sum = i * 100 + j * 10 + k;
                int tmp2 = sum * 2;
                int tmp3 = sum * 3;
                while (tmp2)
                {
                    num_used[tmp2 % 10] = 1;
                    tmp2 /= 10;
                }
                while (tmp3)
                {
                    num_used[tmp3 % 10] = 1;
                    tmp3 /= 10;
                }
                for (int z = 1; z <= 9; z++)
                {
                    if (!num_used[z])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                {
                    cout << sum << ' ' << sum * 2 << ' ' << sum * 3 << ' ' << endl;
                }
                for (int x = 1; x <= 9; x++)
                {
                    num_used[x] = 0;
                }
                flag = 0;
            }
        }
    }
    return 0;
}