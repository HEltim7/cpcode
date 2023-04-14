#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
constexpr int N=1e3+10;
int ans[2][N];
vector<int> adj[N];

void solve() {
    int n;
    cin>>n;
    
    auto add=[&](int x) {
        cout<<"+ "<<x<<endl;
        int in;
        cin>>in;
        return in;
    };

    auto ask=[&](int i,int j) {
        cout<<"? "<<i<<' '<<j<<endl;
        int in;
        cin>>in;
        return in;
    };

    auto fin=[&]() {
        cout<<"! ";
        for(int i=1;i<=n;i++) cout<<ans[0][i]<<' ';
        for(int i=1;i<=n;i++) cout<<ans[1][i]<<" \n"[i==n];
        int in;
        cin>>in;
        return in;
    };

    if(n==2) {
        for(int i=1;i<=n;i++) ans[0][i]=i;
        for(int i=1;i<=n;i++) ans[1][i]=n-i+1;
        fin();
        return;
    }

    add(1+n);
    add(1+n+1);
    vector<pair<int,int>> v;
    for(int i=2;i<=n;i++) v.push_back({ask(1,i),i});
    sort(v.begin(),v.end());

    auto work=[&](int idx) {
        ans[0][idx]=1;
        ans[1][idx]=n/2+1;
        for(int i=1;i<=n;i++) {
            if(i!=idx) {
                int dis=ask(idx,i);
                if(dis&1) {
                    ans[0][i]=n-dis/2;
                    if(n&1) ans[1][i]=ans[1][idx]+(dis+1)/2;
                    else ans[1][i]=ans[1][idx]-(dis+1)/2;
                }
                else {
                    ans[0][i]=ans[0][idx]+dis/2;
                    if(n&1) ans[1][i]=ans[1][idx]-dis/2;
                    else ans[1][i]=ans[1][idx]+dis/2;
                }
            }
        }
    };

    work(v.back().second);
    fin();
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}