#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[26];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    string in;
    cin>>n;
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++) {
        cin>>in;
        for(auto x:in) cnt[x-'a']++;
        cin>>in;
        for(auto x:in) cnt[x-'a']++;
    }
    cin>>in;
    for(auto x:in) cnt[x-'a']++;
    debug(cnt);
    for(int i=0;i<26;i++) 
        if(cnt[i]&1) {
            cout<<(char)(i+'a')<<endl;
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}