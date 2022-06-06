#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL n,a,b;
    LL ans=0;
    cin>>n>>a>>b;
    LL ab=lcm(a,b);
    LL at=n/a,bt=n/b,abt=n/ab;
    ans=(1+n)*n/2;
    if(a<=n) ans-=a*((at+1)*at/2);
    if(b<=n) ans-=b*((bt+1)*bt/2);
    if(ab<=n) ans+=ab*((abt+1)*abt/2);
    cout<<ans;
    return 0;
}