#include <tuple>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
using PID=pair<int,LD>;
constexpr int N=5e4+10;
int len[2][N];
LD cnt[2][N];

PID max(PID x,PID y) {
    if(x.first==y.first) return {x.first,x.second+y.second};
    return std::max(x,y);
}

template<typename T> struct Fenwick {
    bool rev=1;
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim=max(aim,val); }

    void add(int pos,T val) {
        if(rev) pos=N-pos;
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        if(rev) pos=N-pos;
        T res{};
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    void reset(int pos) {
        if(rev) pos=N-pos;
        while(pos<=size) tr[pos]={},pos+=lowbit(pos);
    }
    
    Fenwick(int size):size(size) { tr.resize(size+1); }
};
Fenwick<PID> tr(N+10);

namespace cdq {
    struct Point {
        int h,v,id;
    } p[N],bak[N];
    
    void solve(const int L,const int R,bool rev) {
        auto &le=len[rev];
        auto &cn=cnt[rev];

        if(L==R) {
            int cur=bak[L].id;
            len[rev][cur]++;
            cnt[rev][cur]=max(LD(1),cnt[rev][cur]);
            return;
        }

        int mid=L+R>>1;
        solve(L, mid, rev);

        for(int i=L;i<=R;i++) p[i]=bak[i];
        sort(p+L,p+mid+1,[&](const Point &x,const Point &y) {
            return rev?x.h<y.h:x.h>y.h;
        });
        sort(p+mid+1,p+R+1,[&](const Point &x,const Point &y) {
            return rev?x.h<y.h:x.h>y.h;
        });

        int i=L,j=mid+1;
        while(j<=R) {
            while(i<=mid&&(rev?p[i].h<=p[j].h:p[i].h>=p[j].h)) {
                tr.add(p[i].v, PID(le[p[i].id],cn[p[i].id]));
                i++;
            }
            tie(le[p[j].id],cn[p[j].id])=max(PID{le[p[j].id],cn[p[j].id]},tr.query(p[j].v));
            j++;
        }
        for(int k=L;k<i;k++) tr.reset(p[k].v);
        solve(mid+1, R, rev);
    }

} using cdq::p,cdq::bak;

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>bak[i].h>>bak[i].v,bak[i].id=i;
    bak[n+1]={0,0,n+1};
    n++;
    
    vector<int> num;
    for(int i=1;i<=n;i++) num.push_back(bak[i].v);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());

    for(int i=1;i<=n;i++)
        bak[i].v=lower_bound(num.begin(),num.end(),bak[i].v)-num.begin()+2;

    cdq::solve(1, n, 0);
    reverse(bak+1,bak+1+n);
    tr.rev=0;
    cdq::solve(1, n, 1);

    int maxlen=len[0][n]-1;
    LD tot=cnt[0][n];

    cout<<maxlen<<endl;
    cout<<fixed<<setprecision(15);
    for(int i=1;i<n;i++) {
        if(len[0][i]+len[1][i]-2==maxlen)
            cout<<cnt[0][i]*cnt[1][i]/tot<<' ';
        else cout<<0<<' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}