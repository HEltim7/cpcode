#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
LL n,x,y;

LL dfs(int color,int level) {
    LL res=0;
    if(color==0) {
        if(level>1) res=dfs(0,level-1)+x*dfs(1,level);
    }
    else {
        if(level==1) res=1;
        else res=dfs(0,level-1)+y*dfs(1,level-1);
    }
    return res;
}

void solve() {
    cin>>n>>x>>y;
    cout<<dfs(0,n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}