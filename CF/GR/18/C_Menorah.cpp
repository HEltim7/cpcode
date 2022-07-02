#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int cnta=0,cntb=0;
    for(auto x:a) if(x=='1') cnta++;
    for(auto x:b) if(x=='1') cntb++;
    if(cnta==cntb||cnta+cntb==n+1) {
        int ans=1e9;
        if(cnta==cntb) {
            int res=0;
            for(int i=0;i<n;i++) 
                if(a[i]=='1'&&b[i]=='0') res+=2;
            ans=min(ans,res);
        }
        if(cnta+cntb==n+1) {
            int cnt=0;
            for(int i=0;i<n;i++)
                if(a[i]=='0'&&b[i]=='0') cnt+=2;
            for(int i=0;i<n;i++) {
                int res=1+cnt;
                if(a[i]=='1') {
                    ans=min(ans,res);
                }
            }
        }
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}