#include <algorithm>
#include <array>
#include <cassert>
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
constexpr int N=1e3+10;
map<int,int> d[N];
int pos[N][N];
bool ans[N][N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        d[i].clear();
        for(int j=1;j<=n;j++) {
            ans[i][j]=0;
            int in;
            cin>>in;
            d[i][j]=in;
            pos[i][in]=j;
        }
    }

    while(d[1].size()>=2) {
        for(int i=1;i<=n;i++) {
            auto it=d[i].begin();
            int x=it->second;
            int y=next(it)->second;
            ans[x][y]=ans[y][x]=1;
        }

        int leaf=d[1].rbegin()->second;
        for(int i=1;i<=n;i++) {
            d[i].erase(pos[i][leaf]);
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(ans[i][j]) {
                cout<<i<<' '<<j<<endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}