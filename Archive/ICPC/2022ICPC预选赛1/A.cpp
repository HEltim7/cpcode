#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

const int N=1000006;
ll s[N];
int lc[N],rc[N];//往左连续1的数量，往右连续1的数量
int lid[N],rid[N];//往左第一个0的位置，往右第一个到0的位置
char str[N];
int a[N];
int g[N];

#define debug(x) \
    cerr<<string("[")+string(__func__)+string(" ")+to_string(__LINE__)+string("] ")\
    <<string(#x)+string(" = ")<<x<<endl;
int f(int n)
{
    if(n%2==0) return n/2;
    else return (n-1)/2+2;
}
int main()
{
    int n,Q;
    scanf("%d%d",&n,&Q);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++) a[i]=str[i]-'0';

    rid[n+1]=n+1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            lc[i]=lc[i-1]+1;
            lid[i]=lid[i-1];
        }
        else
        {
            lc[i]=0;
            lid[i]=i;
        }
    }

    for(int i=n;i>=1;i--)
    {
        if(a[i]==1)
        {
            rc[i]=rc[i+1]+1;
            rid[i]=rid[i+1];
        }
        else
        {
            rc[i]=0;
            rid[i]=i;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==1&&a[i+1]==0) s[i]=s[i-1]+f(lc[i]);
        else s[i]=s[i-1];
        if(a[i]==0) g[i]=g[i-1]+1;
        else g[i]=g[i-1];
    }
    while(Q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);

        int L=rid[l];
        int R=lid[r];
        ll num0=0;
        ll numl=0;
        ll numr=0;
        if(a[l]==1) numl+=rc[l];
        if(a[r]==1) numr+=lc[r];
        if(a[l]==a[r]&&a[l]==1)
        {
            num0+=f(numl+numr);
        }
        else if(a[l]!=a[r]&&(a[l]==1||a[r]==1))
        {
            num0+=f(numl)+f(numr);
        }

        if(L<R)
        {
            num0+=s[R]-s[L];
        }
        // debug(num0);
        // debug(numl);
        // debug(numr);
        // debug(L);
        // debug(R);

        ll res=(g[r]-g[l-1])-num0;
        if(res<0) puts("0");
        else
        {
            printf("%lld\n",(res+2)/3);
        }
    }
}