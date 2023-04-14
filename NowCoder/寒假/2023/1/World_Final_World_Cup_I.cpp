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
    string s;
    cin>>s;
    int cnt[]={0,0};
    for(int i=0;i<s.size();i++) {
        int cur=i&1;
        if(s[i]=='1') cnt[cur]++;
        int left=s.size()-i-1;
        int x=left/2;
        int y=(left+1)/2;
        debug(i,left,cnt);
        if(cnt[cur]>cnt[cur^1]+y||cnt[cur]+x<cnt[cur^1]) {
            cout<<i+1<<endl;
            return;
        }
    }
    if(cnt[0]==cnt[1]) cout<<-1<<endl;
    else cout<<s.size()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}