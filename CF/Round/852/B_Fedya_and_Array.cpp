#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int x,y;
    cin>>x>>y;
    vector<int> ans;
    for(int i=x;i>y;i--) ans.push_back(i);
    for(int i=y;i<x;i++) ans.push_back(i);
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}