#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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

void solve() {
    int n,m;
    cin>>n>>m;
    auto ans=vector(n,vector(m,0));
    for(int j=0;j<m;j++) {
        int k=j;
        for(int i=0;i<n;i++) {
            k=(k+1)%m;
            if(k==j) k=(k+1)%m;
            ans[i][k]=j;
        }
    }
    if(m==1) cout<<0<<endl;
    else cout<<min(n+1,m)<<endl;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}