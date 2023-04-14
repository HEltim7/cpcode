#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
LL dp[N][4][2][2];
LL cnt[N][4][2][2];

void f(int i,int a,int b,int c,int x,int y,int z,int val) {
    dp[i][a][b][c]+=dp[i-1][x][y][z]+val*cnt[i-1][x][y][z];
    cnt[i][a][b][c]+=cnt[i-1][x][y][z];
}

void solve() {
    int n;
    cin>>n;
    LL ans=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        for(int j=0;j<=3;j++)
            for(int k=0;k<=1;k++)
                for(int l=0;l<=1;l++) {
                    if(dp[i-1][j][k][l]) {
                        if(in==0) f(i,j,k,l,j,k,l,1);
                        if(in==1) {
                            if(j==3||j==1) f(i,1,k,l,j,k,l,0);
                            else if(j==0) f(i,1,k,l,j,k,l,1);
                            else if(k) f(i,j,k,l,j,k,l,0);
                            else f(i,j,1,l,j,k,l,1);
                        }
                        if(in==2) {
                            if(j==3||j==2) f(i,2,k,l,j,k,l,0);
                            else if(j==0) f(i,2,k,l,j,k,l,1);
                            else if(l) f(i,j,k,l,j,k,l,0);
                            else f(i,j,k,1,j,k,l,1);
                        }
                        if(in==3) {
                            f(i,3,k,l,j,k,l,(j==0));
                        }
                    }
                }
        
        dp[i][in][0][0]++;
        cnt[i][in][0][0]++;
        for(int j=0;j<=3;j++) for(int k=0;k<=1;k++) for(int l=0;l<=1;l++) ans+=dp[i][j][k][l];
    }

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}