#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

namespace cdq {
    constexpr int N=5e4+10;

    struct Point {
        int v,idx;
        bool operator< (const Point &x) const {
            if(idx!=x.idx) return idx<x.idx;
            return v<x.v;
        }
    } p[N],tmp[N],bak[N];

    LL solve(const int l,const int r,bool rev) {
        LL res=0,sum=0,cnt=0;
        if(l==r) return res;
        int mid=l+r>>1;
        res+=solve(l,mid,rev),res+=solve(mid+1,r,rev);

        for(int i=l,j=mid+1,idx=l;j<=r;) {
            while(i<=mid&&(p[i].v+rev<=p[j].v))
                sum+=p[i].idx,cnt++,tmp[idx++]=p[i++];
            res+=(cnt*p[j].idx-sum)*p[j].v;

            tmp[idx++]=p[j++];
            if(j>r) while(i<=mid) tmp[idx++]=p[i++];
        }
        for(int i=l;i<=r;i++) p[i]=tmp[i];
        return res;
    }
} using cdq::p,cdq::bak;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i].v>>p[i].idx;
    sort(p+1,p+1+n);
    for(int i=1;i<=n;i++) bak[i]=p[i];
    LL ans=cdq::solve(1, n, 0);

    for(int i=1;i<=n;i++) p[i]=bak[i];
    int t=p[n].idx;
    reverse(p+1,p+1+n);
    for(int i=1;i<=n;i++) p[i].idx=t-p[i].idx+1;
    ans+=cdq::solve(1, n, 1);

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}