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
using LLL=__int128;
constexpr int N=64;

void solve() {
    LL n,d;
    cin>>n>>d;

    LLL sum=1;
    for(int ans=0;ans<=N;ans++) {
        if(sum>=n) {
            cout<<ans<<endl;
            return;
        }
        sum*=(d+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}