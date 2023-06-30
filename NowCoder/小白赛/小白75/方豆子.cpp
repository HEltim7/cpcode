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
constexpr int N=3.1e3;
bool grid[N][N];

void dfs(int r1,int r2,int c1,int c2,bool type) {
    if(r2-r1+1==6) {
        for(int i=r1;i<=r2;i++) {
            for(int j=c1;j<=c2;j++) {
                bool cur=(i>=r1+3)&&(j>=c1+3);
                grid[i][j]=cur^type;
            }
        }
    }
    else {
        int rmid=(r1+r2)/2;
        int cmid=(c1+c2)/2;
        dfs(r1,rmid,c1,cmid,!type);
        dfs(rmid+1,r2,c1,cmid,!type);
        dfs(r1,rmid,cmid+1,c2,!type);
        dfs(rmid+1,r2,cmid+1,c2,type);
    }
}

void solve() {
    int n;
    cin>>n;
    auto pw=[&](int x) {
        int res=1;
        for(int i=1;i<=x;i++) res*=2;
        return res;
    };

    int r=3*pw(n);
    dfs(1,r,1,r,1);
    for(int i=1;i<=r;i++) {
        for(int j=1;j<=r;j++)
            cout<<(grid[i][j]?'*':'.');
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}