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
    vector<string> s(2);
    string str;
    for(int i=1;i<=n;i++) {
        char c;
        cin>>c;
        str.push_back(c);
        s[i&1].push_back(c);
    }
    sort(s[0].begin(),s[0].end(),greater<>());
    sort(s[1].begin(),s[1].end(),greater<>());
    auto out=[&]() {
        while(s[0].size()||s[1].size()) {
            if(s[1].size()) cout<<s[1].back(),s[1].pop_back();
            if(s[0].size()) cout<<s[0].back(),s[0].pop_back();
        }
        cout<<endl;
    };
    if(k&1) {
        out();
        return;
    }
    else {
        sort(str.begin(),str.end());
        cout<<str<<endl;
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