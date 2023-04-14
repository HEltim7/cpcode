#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL du[N],ud[N],preu[N],sufu[N];

void solve() {
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;

    for(int i=1;i<=n;i++) {
        preu[i]=preu[i-1];
        ud[i]=ud[i-1];
        if(s[i]=='u') preu[i]++;
        else if(s[i]=='d') ud[i]+=preu[i-1];
    }
    for(int i=n;i>=1;i--) {
        sufu[i]=sufu[i+1];
        du[i]=du[i+1];
        if(s[i]=='u') sufu[i]++;
        else if(s[i]=='d') du[i]+=sufu[i+1];
    }

    LL ans=0,idx=0;
    for(int i=1;i<=n;i++) {
        LL cur=0;
        if(s[i]=='d') cur=preu[i-1]*sufu[i+1];
        else if(s[i]=='u') cur=ud[i-1]+du[i+1];
        if(cur>ans) ans=cur,idx=i;
    }
    s[idx]='x';
    for(int i=1;i<=n;i++) cout<<s[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}