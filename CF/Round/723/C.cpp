#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ts;
ll ram;
multiset<ll, greater<ll>> nu;
multiset<ll, greater<ll>>::iterator it;
ll h, d;
ll sum = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> ts;
    for (int i = 0; i < ts; i++)
    {
        cin >> ram;
        if (ram >= 0)
        {
            sum++;
            h += ram;
        }
        else
        {
            ram = -ram;
            if (d + ram <= h)
            {
                sum++;
                nu.insert(ram);
                d += ram;
            }
            else
            {
                if (*nu.begin() > ram)
                {
                    d -= (*nu.begin() - ram);
                    nu.erase(nu.begin());
                    nu.insert(ram);
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}