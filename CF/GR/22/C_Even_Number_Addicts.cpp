#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int res[N][N][2],mark[N][N][2];

int dfs(int n,int k,int type) {
    if(k<0||k>n||n<=0) return -1;
    if(n==1) return k==type;
    if(n==2) return type?k>=1:k<=1;
    if(mark[n][k][type]) return res[n][k][type];
    mark[n][k][type]=1;

    int a=dfs(n-2,k-2,type);
    int b=dfs(n-2,k-1,type);
    int c=dfs(n-2,k-1,!type);
    int d=dfs(n-2,k,!type);

    auto get=[](int a,int b) {
        if(a!=-1&&b!=-1) return min(a,b);
        else if(a!=-1) return a;
        else if(b!=-1) return b;
        return 0;
    };

    res[n][k][type]=max(get(a,b),get(c,d));
    return res[n][k][type];
}

void solve() {
    int n,k=0;
    cin>>n;
    for(int i=1,in;i<=n;i++) cin>>in,k+=!(in&1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int k=0;k<=1;k++) mark[i][j][k]=0;
    if(dfs(n,k,1)) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}