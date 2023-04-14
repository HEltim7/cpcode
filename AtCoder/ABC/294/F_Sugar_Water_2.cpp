#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=5e4+10;
constexpr LD eps=1e-12;
LL sa[N],wa[N];
LL sb[N],wb[N];
LD exa[N],exb[N];

void solve() {
    int n,m;
    LL k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        cin>>sa[i]>>wa[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>sb[i]>>wb[i];
    }

    // 计算比例大于x的混合糖水数量
    auto cal=[&](LD x) {
        LL cnt=0;
        for(int i=1;i<=n;i++) {
            LD s=wa[i]/(1/x-1);
            exa[i]=sa[i]-s;
        }
        for(int i=1;i<=m;i++) {
            LD s=wb[i]/(1/x-1);
            exb[i]=sb[i]-s;
        }

        sort(exa+1,exa+1+n,greater<>());
        sort(exb+1,exb+1+m);

        for(int i=1,j=1;i<=n;i++) {
            while(j<=m&&exa[i]+exb[j]<=0) j++;
            cnt+=m-j+1;
        }
        return cnt;
    };

    LD l=0,r=1;
    while(abs(r-l)>eps) {
        LD mid=(l+r)/2;
        if(cal(mid)<=k-1) r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(15);
    cout<<l*100<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}