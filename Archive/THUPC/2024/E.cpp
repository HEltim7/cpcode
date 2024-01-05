#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    for(int &x:c) cin>>x;

    auto soli=[&]() {
        bool fre=false;
        for(int i=0;i<n;i++) {
            if(a[i]&&b[i]) fre=true;
        }

        LL sumfre=0;
        auto cal=[&](int i) {
            if(a[i]) return min(a[i]+c[i],b[i]);
            else if(fre) return max(0,min(c[i],b[i]-1));
            return 0;
        };

        for(int i=0;i<n;i++) sumfre+=cal(i);
        for(int i=0;i<n;i++) {
            LL res=sumfre-cal(i);
            if(a[i]) res+=a[i]+c[i];
            else if(fre) res+=c[i];
            cout<<res<<" \n"[i==n-1];
        }
    };

    auto soltot=[&]() {
        LL fre=0,tot=0,ans=0;
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(),p.end(),[&](int i,int j) {
            bool x=a[i]>0,y=a[j]>0;
            if(x||y) return x>y;
            x=b[i]>0,y=b[j]>0;
            if(x||y) return x>y;
            return c[i]>c[j];
        });

        for(int i:p) {
            if(a[i]) {
                tot+=a[i]+c[i];
                fre+=min(a[i]+c[i],b[i]);
            }
            else if(fre>0) {
                tot+=c[i];
                fre+=min(c[i],b[i]-1);
            }
            ans=max(ans,tot);
        }
        cout<<ans<<endl;
    };

    soli();
    soltot();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}