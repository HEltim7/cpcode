#pragma GCC optimize("O2")
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
LL ans[N];

struct Point {
    int x,y;
    bool z;
    int id,sign,pw;
    bool operator<(const Point &p) const {
        if(x!=p.x) return x<p.x;
        if(y!=p.y) return y<p.y;
        return z<p.z;
    }
} p[N*5],bak[N*5];

void solve(int l,int r) {
    if(l==r) return;
    int mid=l+r>>1;
    solve(l,mid);solve(mid+1,r);
    LL sum=0;
    for(int i=l,j=mid+1,idx=l;j<=r;) {
        while(i<=mid&&p[i].y<=p[j].y) {
            if(!p[i].z) sum+=p[i].pw;
            bak[idx++]=p[i++];
        }
        if(p[j].z) ans[p[j].id]+=sum*p[j].sign;
        bak[idx++]=p[j++];

        if(j>r) while(idx<=r) bak[idx++]=p[i++];
    }
    for(int i=l;i<=r;i++) p[i]=bak[i];
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y>>p[i].pw;
    for(int i=n,id=1;id<=m;id++) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        p[++i]={x1-1,y1-1,1,id,1};
        p[++i]={x1-1,y2,1,id,-1};
        p[++i]={x2,y1-1,1,id,-1};
        p[++i]={x2,y2,1,id,1};
    }
    sort(p+1,p+1+n+m*4);
    solve(1,n+m*4);
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}