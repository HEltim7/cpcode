#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=20;
int ans[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1,idx=m;i<=n;i+=2,idx=max(idx-1,1)) {
        ans[i][idx]=1;
        for(int j=1;j<=m;j++) cout<<ans[i][j]<<" \n"[j==m];
        if(i+1<=n) {
            ans[i+1][idx]=1;
            for(int j=1;j<=m;j++) cout<<ans[i+1][j]<<" \n"[j==m];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}