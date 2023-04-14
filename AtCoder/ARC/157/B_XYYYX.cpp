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
constexpr int N=2e5+10;

void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    int cntx=0;
    for(auto x:s) cntx+=x=='X';

    int ans=0;
    if(k>cntx) {
        for(char &x:s) x=x=='Y'?'X':'Y';
        k=n-k;
    }
    debug(k,s);

    int side=s[0]=='X';
    vector<pair<int,int>> seg;
    for(int i=0,len=0;i<n;i++) {
        if(s[i]=='Y') {
            if(i&&s[i-1]=='Y') ans++;
            if(len) seg.push_back({side,len}),side=0;
            len=0;
        }
        else len++;
        if(i+1==n&&len) seg.push_back({1+side,len});
    }

    sort(seg.begin(),seg.end());
    debug(seg,ans);
    for(auto [side,len]:seg) {
        if(!k) break;
        if(k>=len) ans+=len+1-side,k-=len;
        else ans+=k-(side>1),k=0;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}