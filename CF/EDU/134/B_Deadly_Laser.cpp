#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m,x,y,d;
    cin>>n>>m>>x>>y>>d;
    int ans=n+m-2;
    if((x+d>=n&&y+d>=m)||(x-d<=1&&y-d<=1)||(x-d<=1&&x+d>=n)||(y-d<=1&&y+d>=m)) ans=-1;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}