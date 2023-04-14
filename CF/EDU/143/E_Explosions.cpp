#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
LL resl[N],resr[N],pre[N];
LL h[N],hi[N];

template<typename T=int> struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) {
        aim=max(aim,val);
    }

    void add(int pos,T val) {
        if(pos<=0) return;
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        if(pos<=0) return 0;
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};

void solve(int n,LL res[]) {
    Fenwick<> pos(n+10);
    vector<int> num;
    for(int i=1;i<=n;i++) hi[i]=h[i]-i,num.push_back(hi[i]);

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        hi[i]=lower_bound(num.begin(),num.end(),hi[i])-num.begin()+1;

    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+h[i];
    for(int i=1;i<=n;i++) {
        pos.add(hi[i], i);
        LL idx=pos.query(hi[i]-1);

        LL len=min(h[i]+1,LL(i)-idx);
        LL x=pre[i]-pre[idx];
        LL y=1LL*(h[i]+(h[i]-len+1))*len/2;

        res[i]=x-y;
        res[i]+=res[idx];
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    solve(n,resl);
    reverse(h+1,h+1+n);
    solve(n,resr);

    reverse(h+1,h+1+n);
    reverse(resr+1,resr+1+n);

    LL ans=1e18;
    for(int i=1;i<=n;i++) {
        LL cur=resl[i]+resr[i]+h[i];
        ans=min(ans,cur);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}