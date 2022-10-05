#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
bool mark[N],bak[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        mark[i]=bak[i]=0;
        char x;
        cin>>x;
        if(x=='0') mark[i]=bak[i]=1;
    }
    LL ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;i*j<=n;j++) {
            int cur=i*j;
            if(!mark[cur]) break;
            if(bak[cur]) ans+=i,bak[cur]=0;
        }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}