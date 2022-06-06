#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int pre[2][N];
int n;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

int check(int i,int one,int x,int &cnt0,int &cnt1) {
    cnt0=pre[0][x]-pre[0][i];
    cnt1=one+pre[1][n]-pre[1][x];
    if(cnt0==cnt1) return 0;
    else if(cnt0<cnt1) return -1;
    return 1;
}

void solve(){
    string in;
    cin>>in;
    in=" "+in;
    n=in.size()-1;
    for(int i=1;i<=n;i++) {
        pre[0][i]=pre[0][i-1]+(in[i]=='0');
        pre[1][i]=pre[1][i-1]+(in[i]=='1');
    }
    int ans=n;
    for(int i=0,one=0;i<=n;i++) {
        int l=i,r=n;
        int cnt0,cnt1;
        if(in[i]=='1') one++;
        while(l<r){
            int mid=l+r>>1;
            int res=check(i,one,mid,cnt0,cnt1);
            ans=min(ans,max(cnt0,cnt1));
            if(res==0) break;
            else if(res==-1) l=mid+1;
            else r=mid-1;
        }
        check(i,one,l,cnt0,cnt1);
        debug(i,l,r,cnt0,cnt1);
        ans=min(ans,max(cnt0,cnt1));
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