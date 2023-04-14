#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n, in, a, b, maxx, country[200];
queue<int> q;

int fn()
{
    if (q.size() < 2)
    {
        return a + b - maxx;
    }
    a = q.front();
    q.pop();
    b = q.front();
    q.pop();
    maxx = max(a, b);
    q.push(maxx);
    return fn();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= pow(2, n); i++)
    {
        cin >> in;
        country[i] = in;
        q.push(in);
    }
    int ans = fn();
    for (int i = 1; i < 200; i++)
    {
        if (country[i] == ans)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}