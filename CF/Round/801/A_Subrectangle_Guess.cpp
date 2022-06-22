#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int grid[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    int maxx=-2e9,r,c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            cin>>grid[i][j];
            if(grid[i][j]>maxx) {
                maxx=grid[i][j];
                r=i,c=j;
            }
        }
    int row=max(r,n-r+1);
    int col=max(c,m-c+1);
    cout<<row*col<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}