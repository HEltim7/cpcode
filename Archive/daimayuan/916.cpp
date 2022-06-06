#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=1e5+10;
int dp[N],idx[N],a[N],edge[12],n,tt;

void add(int pos,int val) {
    while(pos<=n) dp[pos]=max(dp[pos],val),pos+=lowbit(pos);
}

int query(int pos) {
    int res=0;
    while(pos) res=max(res,dp[pos]),pos-=lowbit(pos);
    return res;
}

namespace io {
    const int MAXBUF = 4e5;
    char buf[MAXBUF], *pl, *pr;

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T> T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        return x = x * f;
    }

    template<typename... T> void reads_impl(T&... x) { (rd(x),...); }

    #define read(x) io::rd(x)
    #define reads(...) io::reads_impl(__VA_ARGS__)
}

int main() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) idx[read(tt)]=i;

    for(int i=1;i<=n;i++) {
        tt=1;
        for(int j=-4;j<=4;j++)
            if(a[i]+j>=1&&a[i]+j<=n) edge[tt++]=(idx[a[i]+j]);
        sort(edge+1,edge+tt,greater<int>());
        for(int j=1;j<tt;j++) add(edge[j],query(edge[j]-1)+1);
    }
    printf("%d",query(n));
    return 0;
}