#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef pair<int,int> pii;
typedef long long ll;
const double eps=1e-8;
const int INF=0x3f3f3f3f;
const int N=1000006,M=10000007;
bool st[M];
int primes[M],minp[M],idx;
ll mp[M];//放存进去的答案
namespace IO {
const int MAXSIZE = 1 << 20;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)

inline int rd() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x * f;
}

char pbuf[1 << 20], *pp = pbuf;

inline void push(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}

inline void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) push(sta[--top] + '0');
}
}  // namespace IO
ll qmi(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            if(a>10000000) return a;
            res=res*a;
        }

        if(res>10000000) return res;

        a=a*a;
        b>>=1;
    }
    return res;
}
void init(int n)
{
    st[1]=true;
    minp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) primes[idx++]=i,minp[i]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            minp[primes[j]*i]=primes[j];

            if(i%primes[j]==0) break;
        }
    }
}
int main()
{
    init(M-6);
    int n,k;
    n=IO::rd();
    k=IO::rd();

    ll res=0;
    for(int i=1;i<=n;i++)
    {
        ll fuck=1;
        int val;
        val=IO::rd();
        ll ans=1;
        ll ok=1;
        while(val>1)
        {
            int t=minp[val];
            int cnt=0;
            while(val%t==0)
            {
                val/=t;
                cnt++;
            }
            cnt%=k;
            ans*=qmi(t,cnt);
            fuck=qmi(t,(k-cnt)%k);

            if(fuck<0||fuck>10000000) break;

            ok*=qmi(t,(k-cnt)%k);
            if(ok<0||ok>10000000)
            {
                // ok=0;
                break;
            }
            //if(ok<0||ok>10000000) break;
        }
        if(fuck<0||fuck>10000000) continue;
        if(ok<0||ok>10000000) continue;

        res+=mp[ok];
        mp[ans]++;
    }
    printf("%lld",res);
    return 0;
}
