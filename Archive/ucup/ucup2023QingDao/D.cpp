#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <tuple>
#include <map>
#include <set>
using namespace std;
constexpr int N=1e5+10;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

struct DSU {
    vector<int> fa;
    
    int find(int x) {
        return x==fa[x]?x:fa[x]=find(fa[x]);
    }

    bool join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) return false;
        fa[y]=x;
        return true;
    }

    void init(int n) {
        fa.resize(n+1);
        iota(fa.begin(),fa.end(),0);
    }
};

struct SegSet {
    struct Seg
    {
        int l;
        mutable int r,p;
        bool operator<(const Seg &x) const {
            return l<x.l;
        }
        friend ostream &operator<<(ostream &os,const Seg &x) {
            return os<<"["<<x.l<<"->"<<x.r<<"="<<x.p<<"]";
        }
    };
    DSU dsu;
    set<int> dif;
    set<Seg> st;
    
    void insert(int l,int r,int p) {
        auto lit=--st.upper_bound({l-1});
        auto rit=--st.upper_bound({r+1});
        if(lit->r<l-1) lit++;
        int mnl=l,mxr=r;
        if(lit->r>=l-1&&rit->l<=r+1) {
            mnl=min(mnl,lit->l);
            mxr=max(mxr,rit->r);
            rit++;
            while(lit!=rit) {
                int fa=dsu.find(lit->p);
                dsu.join(p,fa);
                dif.erase(fa);
                dif.insert(p);
                lit=st.erase(lit);
            }
        }
        dif.insert(dsu.find(p));
        st.emplace(mnl,mxr,dsu.find(p));
    }

    auto split(int pos) {
        auto it=st.lower_bound({pos});
        if(it->l==pos) return it;
        it--;
        auto [l,r,fa]=*it;
        st.erase(it);
        st.emplace(l,pos-1,fa);
        return st.emplace(pos,r,fa).first;
    }

    void erase(int l,int r) {
        auto it=split(l);
        auto [L,R,fa]=*it;
        st.erase(it);
        if(r<R) st.emplace(r+1,R,fa);
    }

    SegSet(int n) {
        dsu.init(n);
        st.emplace(-1,-1,-1);
        st.emplace(N,N,N);
    }
};

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    
    vector<LL> s(n+2);
    using T=tuple<bool,int,int,int>;
    auto vec=vector(n+2,vector<T>());
    for(int i=1;i<=k;i++) {
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        if(r1==r2) {
            vec[r1].emplace_back(1,c1,c2,i);
            vec[r1+1].emplace_back(0,c1,c2,i);
            s[r1]+=c2-c1+1;
            s[r2+1]-=c2-c1+1;
        }
        else {
            vec[r1].emplace_back(1,c1,c1,i);
            vec[r2+1].emplace_back(0,c1,c1,i);
            s[r1]++;
            s[r2+1]--;
        }
    }
    
    for(int i=1;i<=n;i++) s[i]+=s[i-1];
    for(int i=1;i<=n;i++) s[i]+=s[i-1];

    auto format=[&](vector<T> &v) {
        vector<int> num(1,-1);
        for(auto [add,l,r,id]:v) {
            num.emplace_back(l);
            num.emplace_back(r);
            num.emplace_back(l-1);
            num.emplace_back(r+1);
        }
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        auto get=[&](int x) {
            return lower_bound(num.begin(),num.end(),x)-num.begin();
        };
        int n=num.size();
        vector<int> sign(n+2),vid(n+2);
        for(auto [add,l,r,id]:v) {
            l=get(l),r=get(r);
            if(add) {
                sign[l]+=2;
                sign[r+1]-=2;
                for(int i=l;i<=r;i++) vid[i]=id;
            }
            else {
                sign[l]--;
                sign[r+1]++;
            }
        }
        partial_sum(sign.begin(),sign.end(),sign.begin());

        vector<T> res;
        for(int i=1,last=i;i<sign.size();i++) {
            if(sign[i]!=sign[last]) {
                if(sign[last]) {
                    res.emplace_back(sign[last]>0?1:0,num[last],num[i-1],vid[last]);
                }
                last=i;
            }
        }
        v=res;
        sort(v.begin(),v.end());
    };

    SegSet st(k);
    for(int i=1;i<=n;i++) {
        if(vec[i].size()) {
            format(vec[i]);
            for(auto [add,l,r,id]:vec[i]) {
                if(add) {
                    st.insert(l,r,id);
                }
                else {
                    st.erase(l,r);
                }
            }
        }
        cout<<s[i]<<' '<<st.dif.size()<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}