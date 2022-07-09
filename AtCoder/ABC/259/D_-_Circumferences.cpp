#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<LL,LL,LL>;
const int N=3e3+10;
int fa[N];
TIII circle[N];

int findfa(int x) {
    if(x==fa[x]) return x;
    return fa[x]=findfa(fa[x]);
}

void solve() {
    int n;
    LL s1,t1,s2,t2;
    cin>>n>>s1>>t1>>s2>>t2;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++) {
        LL x,y,r;
        cin>>x>>y>>r;
        circle[i]={x,y,r};
    }
    for(int i=1;i<=n;i++) {
        auto [x1,y1,r1]=circle[i];
        for(int j=i+1;j<=n;j++) {
            auto [x2,y2,r2]=circle[j];
            LL y=abs(y1-y2);
            LL x=abs(x1-x2);
            LL r=abs(r1-r2);
            if(x*x+y*y<=(r1+r2)*(r1+r2)&&x*x+y*y>=r*r) {
                int a=findfa(i);
                int b=findfa(j);
                fa[a]=b;
            }
        }
    }
    int a=-1,b=-1;
    for(int i=1;i<=n;i++) {
        auto [x,y,r]=circle[i];
        LL s=abs(x-s1);
        LL t=abs(y-t1);
        if(s*s+t*t==r*r) a=i;
        s=abs(x-s2);
        t=abs(y-t2);
        if(s*s+t*t==r*r) b=i;
    }
    a=findfa(a),b=findfa(b);
    if(a==b) cout<<"Yes";
    else cout<<"No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}