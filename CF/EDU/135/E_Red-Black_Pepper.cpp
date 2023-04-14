#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
using PII=pair<int,int>;
constexpr int N=3e5+10;
LL res[N],dif[N];

template<typename T> T exgcd(T a,T b,T &x,T &y) {
    if(!b) { x=1,y=0; return a; }
    T res=exgcd(b, a%b, x, y),t=x;
    x=y,y=t-(a/b)*y;
    return res;
}

void solve() {
    int n;
    cin>>n;
    LL sum=0;
    
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        sum+=a;
        dif[i]=b-a;
    }

    int idx=0;
    LL maxx=0;
    sort(dif+1,dif+1+n);
    for(int i=n;i>=0;i--) {
        res[i]=sum;
        sum+=dif[i];
        if(res[i]>maxx) {
            maxx=res[i];
            idx=i;
        }
    }
    
    int q;
    cin>>q;
    while(q--) {
        LL a,b,x,y;
        cin>>a>>b;
        LL g=exgcd(a, b, x, y);
        if(n%g) {
            cout<<-1<<endl;
            continue;
        }
        x*=n/g;
        y*=n/g;

        LD k=(LD(idx)/a-x)*g/b;
        LL lk=floor(k);
        LL rk=ceil(k);
        LL lx=x+lk*b/g;
        LL rx=x+rk*b/g;
        LL lax=a*lx;
        LL rax=a*rx;

        LL ans=-1;
        if(lax>=0&&lax<=idx) ans=max(ans,res[lax]);
        if(rax<=n&&rax>=idx) ans=max(ans,res[rax]);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}