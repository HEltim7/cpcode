#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;

const int N=2010;
const ll M=1e9+7;
ll dp[N][2],tmp[N][2];//1为上 0为下
int n,m;
int h[N];
ll ans;

void check(){
    bool flag=0;
    for(int i=2;i<=m;i++){
        if(flag==1&&h[i]>h[i-1]) return;
        if(h[i]<h[i-1]) flag=1;
    }
    ans++;
}

void dfs(int deep){
    if(deep>m){
        check();
        return ;
    }
    for(int i=1;i<=n;i++){
        h[deep]=i;
        dfs(deep+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    // for(int i=1;i<=8;i++){
    //     for(int j=1;j<=8;j++){
    //         cout<<i<<' '<<j<<' ';
    //         n=i+1,m=j;
    //         dfs(1);
    //         cout<<ans<<endl;
    //         ans=0;
    //     }
    // }
    n=n+1;
    dfs(1);
    cout<<ans;
}