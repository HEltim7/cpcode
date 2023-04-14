#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    string s,t;
    cin>>n>>k>>s>>t;
    if(s==t) cout<<"YES"<<endl;
    else if(k>=n) cout<<"NO"<<endl;
    else {
        for(int i=n-k;i<=k-1;i++) if(s[i]!=t[i]) {
            cout<<"NO"<<endl;
            return;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        cout<<(s==t?"YES":"NO")<<endl;
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