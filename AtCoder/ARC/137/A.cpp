#include<iostream>
#include<numeric>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL l,r,ans=0;
    cin>>l>>r;
    LL a=min(r,l+1000);
    LL b=max(l,r-1000);
    for(LL i=l;i<=a;i++)
        for(LL j=b;j<=r;j++)
            if(gcd(i,j)==1) ans=max(ans,abs(j-i));
    cout<<ans;
    return 0;
}