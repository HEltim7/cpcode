#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int pre[20][N];

void init() {
    for(int i=1;i<N;i++) {
        for(int k=0;k<20;k++) {
            pre[k][i]=pre[k][i-1];
            if((i&(1<<k))==0) pre[k][i]++;
        }
    }
}

void solve() {
    int l,r;
    cin>>l>>r;
    int andsum=l,ans=r-l;
    for(int i=l;i<=r;i++) andsum&=i;
    if(andsum) cout<<0<<endl;
    else {
        for(int i=0;i<20;i++) {
            int res=pre[i][r]-pre[i][l-1];
            ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    init();
    while(t--) solve();
    return 0;
}