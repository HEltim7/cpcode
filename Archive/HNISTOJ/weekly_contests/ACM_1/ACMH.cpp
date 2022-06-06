#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char matrix[1000][1000][1000]; //迷宫数组
char path[100][1000][1000];    //路径数组
int x, y, startx[1000], starty[1000], request[1000];

int main()
{
    //输入
    int n, size; //测试数/迷宫大小/请求次数
    cin >> n;
    for (int z = 0; z < n; z++)
    {
        cin >> size;
        for (int i = 0; i < size; i++)
        {
            cin >> matrix[z][i];
            for (int j = 0; j < size; j++)
            {
                if (matrix[z][i][j] == 'S')
                {
                    startx[z] = i;
                    starty[z] = j;
                }
            }
        }
        cin >> request[z];
        for (int i = 0; i < request[z]; i++)
        {
            cin >> path[z][i];
        }
    }
    //处理&输出
    for (int z = 0; z < n; z++)
    {
        for (int i = 0; i < request[z]; i++)
        {
            int tmpx = startx[z], tmpy = starty[z];
            for (int j = 0; j < strlen(path[z][i]); j++)
            {
                if (path[z][i][j] == 'U')
                {
                    starty[z]--;
                    if (matrix[z][starty[z]][startx[z]] == '#')
                    {
                        cout << "I am dizzy!" << endl;
                        break;
                    }
                    else if (starty[z] >= size || starty[z] >= size || starty[z] < 0 || starty[z] < 0)
                    {
                        cout << "I am out!" << endl;
                        break;
                    }
                }
                else if (path[z][i][j] == 'D')
                {
                    starty[z]++;
                    if (matrix[z][starty[z]][startx[z]] == '#')
                    {
                        cout << "I am dizzy!" << endl;
                        break;
                    }
                    else if (starty[z] >= size || starty[z] >= size || starty[z] < 0 || starty[z] < 0)
                    {
                        cout << "I am out!" << endl;
                        break;
                    }
                }
                else if (path[z][i][j] == 'L')
                {
                    startx[z]--;
                    if (matrix[z][starty[z]][startx[z]] == '#')
                    {
                        cout << "I am dizzy!" << endl;
                        break;
                    }
                    else if (startx[z] >= size || startx[z] >= size || startx[z] < 0 || startx[z] < 0)
                    {
                        cout << "I am out!" << endl;
                        break;
                    }
                }
                else if (path[z][i][j] == 'R')
                {
                    startx[z]++;
                    if (matrix[z][starty[z]][startx[z]] == '#')
                    {
                        cout << "I am dizzy!" << endl;
                        break;
                    }
                    else if (startx[z] >= size || startx[z] >= size || startx[z] < 0 || startx[z] < 0)
                    {
                        cout << "I am out!" << endl;
                        break;
                    }
                }
            }
            if (matrix[z][starty[z]][startx[z]] == 'T')
            {
                cout << "I get there!" << endl;
            }
            else if (matrix[z][starty[z]][startx[z]] == 'S' || matrix[z][starty[z]][startx[z]] == '.')
            {
                cout << "I have no idea!" << endl;
            }
            startx[z] = tmpx;
            starty[z] = tmpy;
        }
    }

    return 0;
}