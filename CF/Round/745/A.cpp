#include<iostream>
using namespace std;

#define endl '\n'
const int mod=1e9+7;
typedef long long LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL ans=1;
    LL t,n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        ans=1;
        for(int i=3;i<=n*2;i++){
            ans=ans*i%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}