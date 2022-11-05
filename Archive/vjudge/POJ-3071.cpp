#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using DB=double;

constexpr int N=1<<8;
DB p[N][N],ans[N][N];
bool mark[N];

void dfs(int st) {
    
}

void solve() {
    int n;
    cin>>n;
    n=1<<n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>p[i][j];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}