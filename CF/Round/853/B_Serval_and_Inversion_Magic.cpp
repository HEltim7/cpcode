#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;

    int cnt=0;
    vector<int> idx;
    for(int i=1,j=n,pre=0;i<j;i++,j--) {
        if(s[i]!=s[j]) idx.push_back(i);
    }
    for(int i=1;i<idx.size();i++) {
        if(idx[i-1]+1!=idx[i]) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}