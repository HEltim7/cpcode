#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=55;
bool grid[N][N];

void fill(int row,int col,int val) {
    grid[row][col]=val;
    grid[row+1][col]=val;
    grid[row][col+1]=val;
    grid[row+1][col+1]=val;
}

void output(int n,int m) {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cout<<grid[i][j]<<" \n"[j==m];
}

void solve() {
    int n,m;
    cin>>n>>m;
    if(n==2&&m==2) {
        cout<<"1 0"<<endl;
        cout<<"0 1"<<endl;
        return;
    }
    if(n==2) {
        for(int i=2,val=1;i<=m;i+=2,val^=1) grid[1][i]=grid[1][i+1]=val;
        grid[1][1]=!grid[1][2];
        grid[1][m]=!grid[1][m-1];
        for(int i=1;i<=m;i++) grid[2][i]=!grid[1][i];
        output(n,m);
        return;
    }
    else if(m==2) {
        for(int i=2,val=1;i<=n;i+=2,val^=1) grid[i][1]=grid[i+1][1]=val;
        grid[1][1]=!grid[2][1];
        grid[n][1]=!grid[n-1][1];
        for(int i=1;i<=n;i++) grid[i][2]=!grid[i][1];
        output(n,m);
        return;
    }
    for(int i=2;i<n;i+=2)
        for(int j=2;j<m;j+=2) {
            if((i+j>>1)&1) fill(i,j,1);
            else fill(i,j,0);
        }
    for(int j=2;j<m;j++) grid[1][j]=!grid[2][j];
    for(int i=2;i<n;i++) grid[i][1]=!grid[i][2];
    for(int j=2;j<m;j++) grid[n][j]=!grid[n-1][j];
    for(int i=2;i<n;i++) grid[i][m]=!grid[i][m-1];
    grid[1][1]=!grid[1][2];
    grid[n][1]=!grid[n][2];
    grid[1][m]=!grid[1][m-1];
    grid[n][m]=!grid[n][m-1];
    output(n,m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}