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
    int n;
    cin>>n;
    string s;
    cin>>s;

    int ans=0,req=0,pack=0;
    for(auto x:s) if(x>='2') ans++;
    reverse(s.begin(),s.end());

    for(auto x:s) {
        if(x=='0') req++;
        else if(x=='1') {
            if(req) {
                req--;
                ans++;
            }
            else pack++;
        }
    }
    ans+=pack/2;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}