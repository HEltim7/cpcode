#include <bits/stdc++.h>
#define inf 0x3f3f3f3f;
using namespace std;
typedef long long ll;
ll ts;
ll n, m, k;
ll s(ll num)
{
    return num * (num - 1) / 2;
}
int main()
{
    scanf("%lld", &ts);
    while (ts--)
    {
        scanf("%lld%lld%lld", &n, &m, &k);
        ll sn = s(n);
        ll d = inf;

        if (sn < m || m < n - 1)
        {
            puts("NO");
            continue;
        }

        if(n==1){
            d=0;
        }else if (sn == m)
        {
            d = 1;
        }
        else
        {
            d = 2;
        }

        if (d < k - 1)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }

    return 0;
}