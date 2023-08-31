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
    string s,t;
    cin>>s>>t;
    int n=s.size();
    if(s==t) {
        cout<<"YES"<<endl;
        return;
    }

    if(s.front()!=t.front()||s.back()!=t.back()) {
        cout<<"NO"<<endl;
        return;
    }
    if(s.front()==s.back()) {
        cout<<"YES"<<endl;
        return;
    }

    for(int i=0;i<n;i++) {
        if(s[i]==t[i]&&s[i+1]==t[i+1]&&s[i]==s.front()&&s[i+1]==s.back()) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}