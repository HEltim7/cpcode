#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=410;
int grid[N][N];
int up0[N][N],up1[N][N];
int dn0[N][N],dn1[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            char in;
            cin>>in;
            if(in=='#') grid[i][j]=2;
            else if(in=='m') grid[i][j]=1;
            else grid[i][j]=0;
        }

    for(int i=2;i<n;i++)
        for(int j=1;j<=m;j++) {
            for(int k=i,cnt=0;k>=1;k--) {
                cnt+=grid[k][j];
                if(cnt==0) up0[i][j]=i-k;
                else if(cnt==1) up1[i][j]=i-k;
                else break;
            }
            for(int k=i+1,cnt=0;k<=n;k++) {
                cnt+=grid[k][j];
                if(cnt==0) dn0[i][j]=k-i;
                else if(cnt==1) dn1[i][j]=k-i;
                else break;
            }
            up1[i][j]=max(up1[i][j],up0[i][j]);
            dn1[i][j]=max(dn1[i][j],dn0[i][j]);
        }

    int ans=0;
    for(int i=2;i<n;i++)
        for(int l=2,cnt=0;l<m;l++,cnt=0)
            for(int r=l;r<m;r++) {
                cnt+=grid[i][r];
                if(cnt>=2) break;
                int L=l-1,R=r+1,len=r-l+1;
                int u0=min(up0[i][L],up0[i][R]);
                int d0=min(dn0[i][L],dn0[i][R]);
                int u1=min({up1[i][L],up1[i][R],max(up0[i][L],up0[i][R])});
                int d1=min({dn1[i][L],dn1[i][R],max(dn0[i][L],dn0[i][R])});

                if(cnt==1) ans=max(ans,u0&&d0?(u0+d0+1)*2+len:0);
                else {
                    ans=max(ans,u1&&d0?(u1+d0+1)*2+len:0);
                    ans=max(ans,u0&&d1?(u0+d1+1)*2+len:0);
                }
            }

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}