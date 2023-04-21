#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=5e3+20;
LD x[N],y[N],p[20];

void solve() {
    int n,k1,k2,k3,a,b,c;
    cin>>n>>k1>>k2>>k3>>a>>b>>c;
    for(int i=1;i<=k1;i++)
        for(int j=1;j<=k2;j++)
            for(int k=1;k<=k3;k++)
                if(i==a&&j==b&&k==c) p[0]=LD(1)/(k1*k2*k3);
                else p[i+j+k]+=LD(1)/(k1*k2*k3);

    for(int i=n;i>=0;i--) {
        x[i]=p[0];
        y[i]=1;
        for(int j=3;j<=k1+k2+k3;j++) {
            x[i]+=x[i+j]*p[j];
            y[i]+=y[i+j]*p[j];
        }
    }
    
    LD ans=y[0]/(1-x[0]);
    cout<<fixed<<setprecision(12)<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}