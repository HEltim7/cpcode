#include<iostream>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
LL mod=1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n,m,ans=1;
    cin>>n>>m;
    if(m==0){
        cout<<1;
        return 0;
    }
    int bit=0;
    while(m){
        bit++;
        m-=lowbit(m);
    }
    n%=mod;
    for(int i=1;i<=bit;i++) ans=ans*n%mod;
    cout<<ans;
    return 0;
}