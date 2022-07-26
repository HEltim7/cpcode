#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10,mod=998244353;
int p[N],q[N],s[N*2];
int n,cnt[N];
pair<int,int> spos[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

bool match(int a[],int al,int ar,int b[],int bl,int br) {
    while(al<=ar&&bl<=br) {
        if(a[al]!=b[bl]) return 0;
        al++,bl++;
    }
    return 1;
}

void solve() {
    LL ans=1;
    cin>>n;
    memset(cnt, 0, sizeof(int)*(n+1));
    for(int i=1;i<=n;i++) spos[i]={};
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>q[i];
    for(int i=1;i<=2*n;i++) {
        cin>>s[i],cnt[s[i]]++;
        if(spos[s[i]].first==0) spos[s[i]].first=i;
        else spos[s[i]].second=i;
    }
    for(int i=1;i<=n;i++) if(cnt[i]!=2) {
        cout<<0<<endl;
        return;
    }
    for(int a=1,b=1,r=1;a<=n||b<=n;r++) {
        debug(a,b,r,ans);
        if(a<=n&&p[a]==s[r]&&b<=n&&q[b]==s[r]) {
            auto [u,v]=spos[s[r]];
            int len=v-u-1;
            bool x=a+len<=n&&match(p,a,a+len,s,u,u+len);
            bool y=b+len<=n&&match(q,b,b+len,s,u,u+len);
            bool z=v+len<=2*n&&match(s,u,u+len,s,v,v+len);
            if(x&&y&&z) a++,ans=ans*2%mod;
            else if(x) a++;
            else if(y) b++;
            else {
                cout<<0<<endl;
                return;
            }
        }
        else if(a<=n&&p[a]==s[r]) a++;
        else if(b<=n&&q[b]==s[r]) b++;
        else {
            cout<<0<<endl;
            return;
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