#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int t, n, m;
int sum[N][30];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
            for (int j = 0; j < 26; j++)
                sum[i][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char tmp;
                cin >> tmp;
                sum[j][tmp - 'a']++;
            }
        }
        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                char tmp;
                cin >> tmp;
                sum[j][tmp - 'a']--;
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (sum[i][j])
                {
                    char tmp = j + 'a';
                    cout << tmp;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}