#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;
const int N=2010;
const ll M=1e9+7;
ll dp[N][2],tmp[N][2];//1为上 0为下
int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>m>>n;
    n=n+1;
    for(int i=1;i<=n;i++) dp[i][1]=dp[i-1][1]+1;
    while(--m){
        for(int i=1;i<=n;i++) tmp[i][1]=dp[i][1];
        for(int i=1;i<=n;i++) tmp[i][0]=dp[i][0];
        for(int i=1;i<=n;i++){
            dp[i][1]=tmp[i][1];
            dp[i][0]=(tmp[n][1]-tmp[i][1]+tmp[n][0]-tmp[i-1][0]+100*M)%M;
        }
        for(int i=1;i<=n;i++){
            dp[i][1]=(dp[i][1]+dp[i-1][1])%M;
            dp[i][0]=(dp[i][0]+dp[i-1][0])%M;
        }
    }
    cout<<(dp[n][1]+dp[n][0])%M;
    return 0;
}