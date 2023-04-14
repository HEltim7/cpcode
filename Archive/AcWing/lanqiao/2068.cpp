#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
typedef long long ll;

using namespace std;
const int N=1e5+10;
int n,k;
ll num[N],ans;
ll hs[12][N];

ll digit(ll number){
    return (ll)(log10(number)+1);
}

ll power(ll num,ll level){
    while(level--) num*=10;
    return num;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&num[i]);
        ll level=10;
        for(int j=1;j<=10;j++,level*=10){
            ll h=((num[i]%k)*(level%k))%k;
            hs[j][h]++;
        }
    }
    for(int i=1;i<=n;i++){
        ll aim=(k-num[i]%k)%k;
        ans+=hs[digit(num[i])][aim];
        if((power(10,digit(num[i]))%k)*(num[i]%k)%k==aim) ans--;
    }
    cout<<ans;
    return 0;
}