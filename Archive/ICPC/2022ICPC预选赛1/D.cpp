#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define debug(x) \
    cerr<<string("[")+string(__func__)+string(" ")+to_string(__LINE__)+string("] ")\
    <<string(#x)+string(" = ")<<x<<endl;

#define endl '\n'
using LL=long long;
constexpr int N=32;
int dp[2][2][N+5][N+5];//l,r,bit,cnt

void solve() {
    int l,r,bak;
    cin>>l>>r;
    bak=l;
    vector<int> L,R;
    while(l) L.push_back(l&1),l>>=1;
    while(r) R.push_back(r&1),r>>=1;
    while(L.size()<R.size()) L.push_back(0);
    reverse(L.begin(),L.end());
    reverse(R.begin(),R.end());

    // for(auto x:L) cout<<x;
    // cout<<endl;
    // for(auto x:R) cout<<x;
    // cout<<endl;

    memset(dp,-1,sizeof dp);
    if(L.front()==R.front()) 
        dp[1][1][0][L.front()]=L.front();
    else {
        dp[0][1][0][R.front()]=R.front();
        dp[1][0][0][L.front()]=L.front();
    }

    auto update=[](int x,int &y,int v) {
        if(x!=-1&&(y==-1||(y&1)==0)) y=x<<1|v;
    };

    for(int bit=0;bit<L.size()-1;bit++) {
        int l=L[bit+1],r=R[bit+1];
        for(int cnt=0;cnt<=bit+1;cnt++) {
            // dp[0][0]
            update(dp[0][0][bit][cnt],dp[0][0][bit+1][cnt],0);
            update(dp[0][0][bit][cnt],dp[0][0][bit+1][cnt+1],1);
            
            // dp[0][1]
            update(dp[0][1][bit][cnt],dp[0][0==r][bit+1][cnt],0);
            if(r==1) update(dp[0][1][bit][cnt],dp[0][1==r][bit+1][cnt+1],1);

            // dp[1][0]
            if(l==0) update(dp[1][0][bit][cnt],dp[0==l][0][bit+1][cnt],0);
            update(dp[1][0][bit][cnt],dp[1==l][0][bit+1][cnt+1],1);
            
            // dp[1][1]
            if(l==0) update(dp[1][1][bit][cnt],dp[0==l][0==r][bit+1][cnt],0);
            if(r==1) update(dp[1][1][bit][cnt],dp[1==l][1==r][bit+1][cnt+1],1);
        }
    }

    bool flag=0;
    for(int len=1;len*2<=L.size();len++) {
        int bit=L.size()-len-1;
        flag|=bak&(1<<(len-1));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++) {
                if(i&&flag) continue;
                int x=dp[i][j][bit][len];
                if(x!=-1&&(x&1)) {
                    cout<<(x<<len)<<endl;
                    return;
                }
            }
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}