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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(auto x:s) {
        if(x=='B') k--;
    }

    if(k==0) cout<<0<<endl;
    else if(k>0) {
        int idx=0;
        while(k) {
            if(s[idx]=='A') k--;
            idx++;
        }
        cout<<1<<endl;
        cout<<idx<<" B"<<endl;
    }
    else {
        int idx=0;
        while(k) {
            if(s[idx]=='B') k++;
            idx++;
        }
        cout<<1<<endl;
        cout<<idx<<" A"<<endl;
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