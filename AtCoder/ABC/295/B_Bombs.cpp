#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
char grid[N][N];
bool mark[N][N];

void solve() {
    int n,m;
    cin>>n>>m;

    auto work=[&](int r,int c,int val) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(abs(i-r)+abs(j-c)<=val)  
                    mark[i][j]=1;
    };

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>grid[i][j];
            if(grid[i][j]>='1'&&grid[i][j]<='9') {
                work(i, j, grid[i][j]-'0');
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            if(mark[i][j]) cout<<'.';
            else cout<<grid[i][j];
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}