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
    vector<int> pos(n+1);
    for(int i=1,in;i<=n;i++) cin>>in,pos[in]=i;
    int x,y;
    cin>>x>>y;
    cout<<(abs(pos[x]-pos[y])==1?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}