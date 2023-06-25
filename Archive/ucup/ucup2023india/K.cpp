#include <algorithm>
#include <array>
#include <bitset>
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

void solve() {
    int n,m;
    cin>>n>>m;
    int h=__lg(m);
    vector<int> val;
    for(int i=1;i<7;i++) {
        int v=0;
        for(int j=0;j<3;j++) {
            if(i>>j&1) v|=m<<((h+1)*j);
        }
        val.push_back(v);
    }

    for(int i=1;i<=n;i++) {
        for(int x:val) cout<<x<<' ';
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}