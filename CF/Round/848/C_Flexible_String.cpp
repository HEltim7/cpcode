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
bool mark[1<<7];

void solve() {
    int n,k;
    cin>>n>>k;
    string a,b;
    cin>>a>>b;
    vector<char> ch;
    for(auto x:a) ch.push_back(x);
    sort(ch.begin(),ch.end());
    ch.erase(unique(ch.begin(),ch.end()),ch.end());
    a=" "+a,b=" "+b;

    LL ans=0;
    for(int i=0;i<1<<ch.size();i++) {
        if(__builtin_popcount(i)>k) continue;
        for(int c='a';c<='z';c++) mark[c]=0;
        for(int j=0;j<ch.size();j++) if(i>>j&1) mark[ch[j]]=1;
        LL res=0;
        for(int j=1,cur=0;j<=n;j++) {
            if(mark[a[j]]||a[j]==b[j]) cur++;
            else res+=1LL*(cur+1)*cur/2,cur=0;
            if(j==n) res+=1LL*(cur+1)*cur/2;
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}