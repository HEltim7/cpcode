#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
int ans[N][N];

void solve() {
    int n,m;
    cin>>n>>m;

    for(int i=0,idx=1;i<n;i++) {
        for(int j=0;j<m;j++) {
            ans[i][j]=idx*m+j;
        }
        idx+=2;
        if(idx>=n) idx=0;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cout<<ans[i][j]+1<<" \n"[j==m-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}