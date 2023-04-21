#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;
    if(s.front()=='0') {
        cout<<0<<endl;
        return;
    }

    int ans=1;
    for(int i=0,j=1;i<s.size();i++) {
        if(s[i]=='?') {
            if(i==0) ans*=9;
            else ans*=10;
        }
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