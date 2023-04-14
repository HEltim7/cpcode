#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s,t;
    cin>>n>>s>>t;
    s=" "+s+"#",t=" "+t+"#";
    bool res=1;
    for(int i=1,cnt=0;i<=n;i++) {
        if(t[i]=='1') cnt++; else cnt--;
        if(s[i]!=t[i]&&(s[i+1]==t[i+1])) if(cnt) res=0;
        if(s[i]==t[i]&&(s[i+1]!=t[i+1])) if(cnt) res=0;
    }
    cout<<(res?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}