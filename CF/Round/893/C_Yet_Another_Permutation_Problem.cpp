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
    int n;
    cin>>n;
    vector<int> ans;
    vector<bool> mark(n+1);
    ans.emplace_back(1);
    mark[1]=1;
    for(int i=2;i<=n;i++) {
        if(mark[i]) continue;
        int j=i;
        while(j<=n) ans.emplace_back(j),mark[j]=1,j*=2;
    }
    for(int x:ans) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}