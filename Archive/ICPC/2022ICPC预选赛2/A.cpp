#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N=102,M=1000006;
int a[N][N];
int power[M];
ll qmi(ll a,ll b,ll p)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*a%p;

        a=a*a;
        b>>=1;
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);

    while(T--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1;i<=min(n,100);i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int Q;
        scanf("%d",&Q);
        while(Q--)
        {
            ll res=0;
            int p;
            scanf("%d",&p);
            if(n<=100){
            for(int i=n-1,t=1;i>=0&&t<=100;i--,t++)
            {
                ll ans=a[min(n,100)][t]*qmi(10,i,p);
                res=(res+ans)%p;
            }

            printf("%lld\n",res);
            }else{
                printf("0\n");
            }

        }
    }
}