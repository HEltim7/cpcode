#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=20;
int grid[N][N];

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string in;
        cin>>in;
        for(int j=0;j<n;j++)
            grid[i][j]=in[j]-'0';
    }
    int mvr[]={1,1,1,0,0,-1,-1,-1};
    int mvc[]={1,0,-1,1,-1,1,0,-1};
    LL ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<8;k++) {
                int r=i,c=j;
                LL res=0;
                for(int x=1;x<=n;x++) {
                    res=res*10+grid[r][c];
                    r=(r+mvr[k]+n)%n;
                    c=(c+mvc[k]+n)%n;
                }
                ans=max(ans,res);
            }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}