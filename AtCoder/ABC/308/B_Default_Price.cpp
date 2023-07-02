#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    vector<string> vs;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        vs.push_back(s);
    }

    vector<string> str;
    map<string,int> mp;
    for(int i=1;i<=m;i++) {
        string s;
        cin>>s;
        str.push_back(s);
    }
    int de;
    cin>>de;

    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        mp[str[i-1]]=in;
    }

    int sum=0;
    for(auto x:vs) {
        if(mp.find(x)==mp.end()) sum+=de;
        else sum+=mp[x];
    }
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}