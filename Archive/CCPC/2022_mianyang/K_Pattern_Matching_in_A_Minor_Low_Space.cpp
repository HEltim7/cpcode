#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2,p=13331;
constexpr int mod[N]={998244353,int(1e9+7)};
LL hashv[N],res[N];

void solve() {
    int n,m;
    cin>>n>>m;
    
    int ans=0;
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        for(int j=0;j<N;j++) {
            hashv[j]=(hashv[j]*p+in)%mod[j];
        }
    }

    for(int i=1;i<=m;i++) {
        char in;
        cin>>in;
        for(int j=0;j<N;j++) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}