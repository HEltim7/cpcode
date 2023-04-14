#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,a,b;
    string s;
    cin>>n>>a>>b>>s;
    s=" "+s;
    
    LL ans=1LL*n/2*b;
    for(int i=0;i<n;i++) {
        LL res=1LL*a*i;
        string cur=" ";
        for(int j=i+1;j<=n;j++) cur.push_back(s[j]);
        for(int j=1;j<=i;j++) cur.push_back(s[j]);
        for(int l=1,r=n;l<=n/2;l++,r--) if(cur[l]!=cur[r]) res+=b;
        ans=min(ans,res);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}