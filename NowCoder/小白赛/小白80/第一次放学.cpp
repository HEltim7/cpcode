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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> cnt(m+1);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        cnt[in]++;
    }
    int mx=*max_element(cnt.begin(),cnt.end());
    cout<<min(mx,n-k)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}