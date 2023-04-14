#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
int ans[N];

namespace cdq {

    template<typename T=int> struct Fenwick {
        int size=0;
        vector<T> tr;
    
        int lowbit(int x) { return x&(-x); }
    
        void update(T &aim,const T &val) { aim=max(aim,val); }

        void reset(int pos) {
            while(pos<=size) tr[pos]=-1e9,pos+=lowbit(pos);
        }
    
        void add(int pos,T val) {
            while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
        }
    
        T query(int pos) {
            T res=-1e9;
            while(pos) update(res,tr[pos]),pos-=lowbit(pos);
            return res;
        }
    
        Fenwick(int size):size(size) { tr.resize(size+1,-1e9); }
    };
    Fenwick<> tr(N);

    struct Point {
        int x,y,t;
        bool type;
        int id;
        bool operator<(const Point &p) const {
            if(x!=p.x) return x<p.x;
            if(y!=p.y) return y<p.y;
            if(t!=p.t) return t<p.t;
            return type<p.type;
        }
    } p[N<<1],tmp[N<<1],bak[N<<1];

    void solve(const int L,const int R) {
        if(L==R) return;
        int mid=L+R>>1;
        solve(L,mid),solve(mid+1,R);
        for(int i=L,j=mid+1,idx=L;j<=R;) {
            while(i<=mid&&p[i].y<=p[j].y) {
                if(!p[i].type) tr.add(p[i].t,p[i].x+p[i].y);
                tmp[idx++]=p[i++];
            }
            if(p[j].type) ans[p[j].id]=min(ans[p[j].id],p[j].x+p[j].y-tr.query(p[j].t));

            tmp[idx++]=p[j++];
            if(j>R) {
                for(int k=L;k<i;k++) tr.reset(p[k].t);
                while(i<=mid) tmp[idx++]=p[i++];
            }
        }
        for(int i=L;i<=R;i++) p[i]=tmp[i];
    }

} using cdq::p,cdq::bak;

void solve() {
    int n,m,qid=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    for(int i=n+1;i<=n+m;i++) {
        int type;
        cin>>type>>p[i].x>>p[i].y;
        p[i].t=i-n;
        if(type==2) p[i].type=1,p[i].id=++qid;
    }
    for(int i=1;i<=n+m;i++) p[i].t++;

    for(int i=1;i<=n+m;i++) bak[i]=p[i];
    for(int i=1;i<=qid;i++) ans[i]=1e9;

    auto rev=[&](auto get) {
        int maxx=0,minn=1e9;
        for(int i=1;i<=n+m;i++) maxx=max(maxx,get(i)),minn=min(minn,get(i));
        for(int i=1;i<=n+m;i++) get(i)=maxx-get(i)+minn;
    };

    sort(p+1,p+1+n+m);
    cdq::solve(1,n+m);

    for(int i=1;i<=n+m;i++) p[i]=bak[i];
    rev([](int idx) -> int& { return p[idx].x; });
    sort(p+1,p+1+n+m);
    cdq::solve(1,n+m);

    for(int i=1;i<=n+m;i++) p[i]=bak[i];
    rev([](int idx) -> int& { return p[idx].y; });
    sort(p+1,p+1+n+m);
    cdq::solve(1,n+m);
    
    for(int i=1;i<=n+m;i++) p[i]=bak[i];
    rev([](int idx) -> int& { return p[idx].x; });
    rev([](int idx) -> int& { return p[idx].y; });
    sort(p+1,p+1+n+m);
    cdq::solve(1,n+m);

    for(int i=1;i<=qid;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}