//记忆化
//不开unsigned long long 见祖宗
#include <iostream>
using namespace std;
#define ull unsigned long long
int board[50][50];
int bx, by, hx, hy;
ull ways;
ull mem[50][50];

ull next(int x, int y)
{
    if (board[x][y]) //控制点
    {
        return 0;
    }
    else if (mem[x][y]) //记忆点
    {
        return mem[x][y];
    }
    else if (x == bx && by == y) //到达
    {
        return 1;
    }
    else if (x < bx & y == by) //触y
    {
        mem[x][y] = next(x + 1, y);
        return mem[x][y];
    }
    else if (x == bx & y < by) //触x
    {
        mem[x][y] = next(x, y + 1);
        return mem[x][y];
    }
    else
    {
        mem[x][y] = next(x + 1, y) + next(x, y + 1);
        return mem[x][y];
    }
}

int main()
{
    cin >> bx >> by >> hx >> hy;

    //p1->p8 & h
    board[hx][hy] = 1;
    board[hx + 2][hy + 1] = 1;
    board[hx + 1][hy + 2] = 1;

    if (hx - 1 >= 0 && hy + 2 >= 0)
        board[hx - 1][hy + 2] = 1;
    if (hx - 2 >= 0 && hy + 1 >= 0)
        board[hx - 2][hy + 1] = 1;

    if (hx - 2 >= 0 && hy - 1 >= 0)
        board[hx - 2][hy - 1] = 1;
    if (hx - 1 >= 0 && hy - 2 >= 0)
        board[hx - 1][hy - 2] = 1;

    if (hx + 1 >= 0 && hy - 2 >= 0)
        board[hx + 1][hy - +2] = 1;
    if (hx + 2 >= 0 && hy - 1 >= 0)
        board[hx + 2][hy - 1] = 1;

    ways = next(0, 0);
    cout << ways;
    return 0;
}