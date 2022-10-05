#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=5e3+10;
constexpr LL INF=0x3f3f3f3f3f3f3f3f;
LL dp[N][4],res[N],tmp[N];
int arr[N];

void solve() {
    int m=0;
    int n;
    LL x,y;
    cin>>n>>x>>y;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<n;i++) if(a[i]!=b[i]) arr[++m]=i+1;
    if(m&1) {
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<=n;i++) memset(dp[i], 0x3f, sizeof(dp[i]));
    for(int i=0;i<=n;i++) res[i]=tmp[i]=0;

    for(int i=2;i<=m;i+=2) {
        res[i-1]=res[i-2];
        res[i]=res[i-2]+(arr[i]-arr[i-1])*x;
    }
    for(int i=3;i<=m;i+=2) {
        tmp[i-1]=tmp[i-2];
        tmp[i]=tmp[i-2]+(arr[i]-arr[i-1])*x;
    }
    tmp[m]=tmp[m-1];
    
    dp[0][0]=0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<=3;j++) {
            dp[i+2][j]=min(dp[i+2][j],dp[i][j]+x*2*(arr[i+2]-arr[i+1]));
            dp[i+1][min(3,j+1)]=min(dp[i+1][min(3,j+1)],dp[i][j]+y);
        }
    }
    LL ans=min(dp[m][0],dp[m][3])/2;
    for(int i=1;i<m;i++)
        for(int j=i+1;j<=m;j++) {
            LL val=tmp[j]-tmp[i]-(res[j]-res[i]);
            if(arr[j]-arr[i]==1)
                ans=min(ans,res[m]+val+min(x,min(x,y)+y));
            else
                ans=min(ans,res[m]+val+min((arr[j]-arr[i])*x,y));
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