#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    LL ans=0,len=0,cnt0=0,cnt1=0;
    char cur='-';
    for(int i=0;i<n;i++) {
        if(s[i]=='0') cnt0++;
        else cnt1++;
        if(s[i]!=cur) {
            cur=s[i];
            len=1;
        }
        else len++;
        ans=max(ans,len*len);
    }
    ans=max(ans,cnt0*cnt1);
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