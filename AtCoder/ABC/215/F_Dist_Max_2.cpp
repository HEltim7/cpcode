#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10,INF=1e9;
int x[N],y[N],z[N],rz[N];

template<typename T=int> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim=min(aim,val); }

    void add(int pos,T val) {
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res{INF};
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    void reset() {
        tr=vector<T>(size+1,INF);
    }

    Fenwick(int size):size(size) { tr.resize(size+1,INF); }
};
Fenwick<> trX(N),trY(N);

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];

    int ans=0;
    auto work=[&]() {
        vector<int> num;
        for(int i=1;i<=n;i++) z[i]=y[i]-x[i];
        for(int i=1;i<=n;i++) num.push_back(z[i]);
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        for(int i=1;i<=n;i++) 
            z[i]=lower_bound(num.begin(),num.end(),z[i])-num.begin()+1;
        for(int i=1;i<=n;i++) rz[i]=n-z[i]+1;

        trX.reset();
        trY.reset();
        for(int i=1;i<=n;i++) {
            trX.add(z[i], x[i]);
            trY.add(rz[i], y[i]);
        }
        for(int i=1;i<=n;i++) {
            int maxy=y[i]-trY.query(rz[i]);
            ans=max(ans,maxy);
            int maxx=x[i]-trX.query(z[i]);
            ans=max(ans,maxx);
        }
    };

    work();
    int maxy=0,miny=INF;
    for(int i=1;i<=n;i++) maxy=max(maxy,y[i]),miny=min(miny,y[i]);
    for(int i=1;i<=n;i++) y[i]=maxy-y[i]+miny;
    work();

    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}