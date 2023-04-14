#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e3+10;

struct Gun {
    LL f,d,p;
    bool operator<(const Gun &g) const {
        return p<g.p;
    }
} g[N];

void solve() {
    int n,dif;
    cin>>n>>dif;
    for(int i=1;i<=n;i++) cin>>g[i].f;
    for(int i=1;i<=n;i++) cin>>g[i].d;
    for(int i=1;i<=n;i++) g[i].p=g[i].f*g[i].d;
    sort(g+1,g+n+1);

    auto check=[&](int len) {
        for(int i=1,j=i+len-1;j<=n;i++,j++) {
            vector<pair<LL,LL>> v;
            LL minn=g[i].p;
            LL maxx=g[j].p;
            for(int k=1;k<i;k++) {
                LL d=(g[i].p+g[k].f-1)/g[k].f;
                LL p=d*g[k].f;
                if(p>g[j].p) {
                    v.emplace_back(p-g[k].f,p);
                }
            }
            for(int k=j+1;k<=n;k++) {
                LL d=(g[i].p+g[k].f-1)/g[k].f;
                LL p=d*g[k].f;
                if(p>g[j].p) {
                    if(g[k].f>g[j].p) maxx=max(maxx,g[k].f);
                    else v.emplace_back(p-g[k].f,p);
                }
            }
            
            if(maxx-minn>dif) continue;
            v.emplace_back(minn, maxx);
            sort(v.begin(),v.end());
            for(auto [l,r]:v) {
                minn=l;
                if(maxx-l<=dif) return true;
                maxx=max(maxx,r);
            }
        }
        return false;
    };

    int L=0,R=n;
    while(L<R) {
        int mid=L+R+1>>1;
        if(check(mid)) L=mid;
        else R=mid-1;
    }
    cout<<n-L<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}