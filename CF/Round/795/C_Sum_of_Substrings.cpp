#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0,pre=-1,suf=-1;
    for(int i=0;i<s.size();i++)
        if(s[i]=='1') {
            cnt++;
            if(pre==-1) pre=i+1;
            suf=i+1;
        }
    int ans=cnt*11;
    if(cnt>=2) {
        //suf
        if(n-suf<=k) k-=(n-suf),ans-=10;
        if(pre-1<=k) ans--;
    }
    else if(cnt==1){
        if(n-suf<=k) ans-=10;
        else if(suf-1<=k) ans--;
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