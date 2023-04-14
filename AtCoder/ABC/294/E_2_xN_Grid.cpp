#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int a[N],b[N];
LL la[N],lb[N];

void solve() {
    LL L;
    int n,m;
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>la[i],la[i]+=la[i-1];
    for(int i=1;i<=m;i++) cin>>b[i]>>lb[i],lb[i]+=lb[i-1];
    LL ans=0;
    
    LL p=0,q=0;
    LL x=1,y=lb[1];
    int va=-1,vb=b[1];
    for(int i=0,j=1;j<=m;) {
        while(i<n&&q<y) {
            p=la[i]+1;
            q=la[++i];
            va=a[i];
            if(va==vb) ans+=max(0LL,min(q,y)-max(p,x)+1);
        }
        x=lb[j]+1;
        y=lb[++j];
        vb=b[j];
        if(va==vb) ans+=max(0LL,min(q,y)-max(p,x)+1);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}