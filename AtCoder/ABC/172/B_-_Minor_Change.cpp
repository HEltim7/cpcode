#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s,t;
    cin>>s>>t;
    int ans=0;
    for(int i=0;i<s.size();i++) ans+=s[i]!=t[i];
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}