#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=20;
int grid[N][N];

int n,m,ans;
set<int> st;
void dfs(int r,int c) {
    if(r==n&&c==m) {
        ans++;
        return;
    }
    if(r+1<=n&&!st.count(grid[r+1][c])) {
        st.insert(grid[r+1][c]);
        dfs(r+1,c);
        st.erase(grid[r+1][c]);
    }
    if(c+1<=m&&!st.count(grid[r][c+1])) {
        st.insert(grid[r][c+1]);
        dfs(r,c+1);
        st.erase(grid[r][c+1]);
    }
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            cin>>grid[i][j];
    st.insert(grid[1][1]);
    dfs(1,1);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}