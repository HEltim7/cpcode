#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
constexpr int N = 1e3+10;
int arr[N][N];
int col[N],row[N];

void solve() {
    int n,m;
    cin>>n>>m;
    memset(col, 0x3f, sizeof col);
    memset(row, 0x3f, sizeof row);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
            col[j]=min(col[j],arr[i][j]);
            row[i]=min(row[i],arr[i][j]);
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            ans+=arr[i][j]==min(row[i],col[j]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}