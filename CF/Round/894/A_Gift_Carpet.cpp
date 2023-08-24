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
    int n,m;
    cin>>n>>m;
    vector<string> arr(m+1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            arr[j].push_back(in);
        }
    }

    string s="vika";
    int idx=0;
    for(int i=1;i<=m&&idx<s.size();i++) {
        if(find(arr[i].begin(),arr[i].end(),s[idx])!=arr[i].end()) idx++;
    }
    if(idx==s.size()) cout<<"YES"<<endl;
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