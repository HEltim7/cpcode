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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

vector<vector<int>> kmp_build(string s) {
    int n=s.size();
    s=" "+s;
    vector<int> link(n+1);
    auto adj=vector<vector<int>>(n+1);
    for(int i=2,j=0;i<=n;i++) {
        while(j&&s[i]!=s[j+1]) j=link[j];
        if(s[i]==s[j+1]) j++;
        link[i]=j;
    }
    for(int i=1;i<=n;i++) adj[link[i]].push_back(i);
    return adj;
}

void solve() {
    string s;
    cin>>s;
    auto &&adj=kmp_build(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}