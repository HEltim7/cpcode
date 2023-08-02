#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    int n,p,q;
    cin>>n>>p>>q;
    int minn=1e9;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        minn=min(minn,in);
    }
    cout<<min(minn+q,p)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}