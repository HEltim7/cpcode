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
    string s;
    cin>>s;
    int pre=m,maxx=m,tot=m;
    for(auto x:s) {
        if(x=='+') pre++,tot++;
        else pre--;
        maxx=max(maxx,pre);
    }
    if(maxx>=n) cout<<"YES"<<endl;
    else if(tot>=n) cout<<"MAYBE"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}