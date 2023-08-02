#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e3+10;
int arr[N][N],pre[N][N];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++) {
        int x,y;
        cin>>x>>y;
        arr[x][y]=1;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+arr[i][j];
        }
    }

    auto get=[&](int r,int c,int x,int y) {
        return pre[x][y]-pre[x][c-1]-pre[r-1][y]+pre[r-1][c-1];
    };

    LL ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(arr[i][j]) continue;
            int l=0,r=min(n-i,m-j);
            while(l<r) {
                int mid=(l+r+1)/2;
                if(get(i,j,i+mid,j+mid)==0) l=mid;
                else r=mid-1;
            }
            ans+=l+1;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}