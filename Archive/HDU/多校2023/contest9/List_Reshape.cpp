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
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    string s;
    getline(cin,s);
    getline(cin,s);
    cin>>n>>m;

    int idx=0;
    auto next_int=[&]() {
        string res;
        while(idx<s.size()) {
            char x=s[idx++];
            if(x=='[') continue;
            else if(x==']') return res;
            else if(x==',') return res;
            else if(isdigit(x)) res+=x;
        }
        return res;
    };

    string ans="[";
    for(int i=1;i<=n;i++) {
        string cur="[";
        for(int j=1;j<=m;j++) {
            cur+=next_int();
            if(j<m) cur+=", ";
        }
        cur+="]";
        ans+=cur;
        if(i<n) ans+=", ";
    }
    ans+="]";
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}