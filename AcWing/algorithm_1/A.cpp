#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[105];
ll b[105];
ll nu[105];
ll ts;
ll n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> ts;
    while (ts--)
    {
        cin >> n;
        for (ll i = 0; i < n * 2; i++)
        {
            cin >> nu[i];
        }
        sort(nu, nu + n * 2);
        for (ll i = 0; i < n; i++)
        {
            cout << nu[i] << " " << nu[n + i] << " ";
        }
        cout << endl;
    }

    return 0;
}