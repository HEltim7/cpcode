#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=N*10;

template<typename T=int,T init=T()> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=init;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    void reset(int pos) {
        while(pos<=size) {
            tr[pos]=init;
            pos+=lowbit(pos);
        }
    }

    void resize(int n) {
        size=n;
        tr.resize(size+1,init);
    }

    Fenwick()=default;
    Fenwick(int n):size(n) { tr.resize(size+1,init); }
};

Fenwick<> tr(M);

namespace cdq {
    constexpr int N=M;
    LL ans;

    struct Point {
        int x,y,z,sign;
        bool q;
        bool operator<(const Point &p) const {
            return x<p.x;
        }
    } p[N],tmp[N],bak[N];

    void solve(const int L,const int R) {
        if(L==R) return;
        int mid=L+R>>1;
        solve(L,mid),solve(mid+1,R);

        int i=L,j=mid+1,idx=L;
        while(j<=R) {
            while(i<=mid&&p[i].y<=p[j].y) {
                if(!p[i].q) tr.add(p[i].z, 1);
                tmp[idx++]=p[i++];
            }
            if(p[j].q) {
                debug(p[j].x,p[j].y,p[j].z);
                debug(tr.query(p[j].z)*p[j].sign);
                debug();
                ans+=tr.query(p[j].z)*p[j].sign;
            }
            tmp[idx++]=p[j++];
        }
        for(int k=L;k<i;k++) if(!p[k].q) tr.reset(p[k].z);
        while(i<=mid) tmp[idx++]=p[i++];
        for(int i=L;i<=R;i++) p[i]=tmp[i];
    }

} using cdq::p,cdq::bak;

int pl[N][3],pr[N][3];

void solve() {
    int w,h,l;
    cin>>w>>h>>l;
    __int128 totv=__int128(w)*h*l;

    int n;
    cin>>n;
    vector<int> num;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) cin>>pl[i][j],num.emplace_back(pl[i][j]);
        for(int j=0;j<3;j++) cin>>pr[i][j],num.emplace_back(pr[i][j]);
        totv-=__int128(pr[i][0]-pl[i][0])*(pr[i][1]-pl[i][1])*(pr[i][2]-pl[i][2]);
        for(int j=0;j<3;j++) num.emplace_back(++pl[i][j]);
    }

    debug(totv);
    if(totv) {
        cout<<"No"<<endl;
        return;
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) {
            pl[i][j]=lower_bound(num.begin(),num.end(),pl[i][j])-num.begin()+1;
            pr[i][j]=lower_bound(num.begin(),num.end(),pr[i][j])-num.begin()+1;
        }
    }
    
    int idx=0;
    for(int i=1;i<=n;i++) {
        p[++idx]={pl[i][0],pl[i][1],pl[i][2],0,0};
        p[++idx]={pr[i][0],pr[i][1],pr[i][2],1,1};
    }
    sort(p+1,p+1+idx);
    cdq::solve(1, idx);
    cdq::ans-=n;
    debug(cdq::ans);
    debug("==========");

    idx=0;
    for(int i=1;i<=n;i++) {
        int x=pr[i][0],y=pr[i][1],z=pr[i][2];
        int xx=pl[i][0]-1,yy=pl[i][1]-1,zz=pl[i][2]-1;
        p[++idx]={x,y,z,0,0};
        p[++idx]={xx,y,z,-1,1};
        p[++idx]={x,yy,z,-1,1};
        p[++idx]={x,y,zz,-1,1};
        p[++idx]={xx,yy,z,1,1};
        p[++idx]={xx,y,zz,1,1};
        p[++idx]={x,yy,zz,1,1};
        p[++idx]={xx,yy,zz,-1,1};
    }
    sort(p+1,p+1+idx);
    cdq::solve(1, idx);
    debug(cdq::ans);

    // 特判完全相同的cube
    cout<<(cdq::ans==0?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}