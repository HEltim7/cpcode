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

void solve() {
    LL n,m,k;
    string s;
    cin>>n>>m>>k;

    LL xcnt=0;
    for(auto x:s) xcnt+=x=='x';
    if(xcnt*m==k) {
        cout<<n*m;
        return;
    }

    LL t=max(k/xcnt-1,0LL);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}