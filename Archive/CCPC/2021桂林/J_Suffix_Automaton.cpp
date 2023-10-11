#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
constexpr int N=1e6+10;

namespace SA {
    string s;
    int fir[N],sec[N],cnt[N];
    int sa[N],rk[N],height[N];

    void get_sa() {
        int m=1<<7;
        int n=s.size()-1;
        for(int i=1;i<=n;i++) cnt[fir[i]=s[i]]++;
        for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i;i--) sa[cnt[fir[i]]--]=i;

        for(int k=1;k<=n;k<<=1) {
            int num=0;
            for(int i=n-k+1;i<=n;i++) sec[++num]=i;
            for(int i=1;i<=n;i++) if(sa[i]>k) sec[++num]=sa[i]-k;
            for(int i=1;i<=m;i++) cnt[i]=0;
            for(int i=1;i<=n;i++) cnt[fir[i]]++;
            for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1];
            for(int i=n;i;i--) sa[cnt[fir[sec[i]]]--]=sec[i],sec[i]=0;
            swap(fir,sec);
            fir[sa[1]]=num=1;
            for(int i=2;i<=n;i++)
                fir[sa[i]]=(sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+k]==sec[sa[i-1]+k])
                    ?num:++num;
            if(num==n) break;
            m=num;
        }
    }

    void get_height() {
        int n=s.size()-1;
        for(int i=1;i<=n;i++) rk[sa[i]]=i;
        for(int i=1,k=0;i<=n;i++) {
            if(rk[i]==1) continue;
            if(k) k--;
            int j=sa[rk[i]-1];
            while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) k++;
            height[rk[i]]=k;
        }
    }
} using SA::sa,SA::rk,SA::height;

template<typename T=int,T init=T()> struct Fenwick {
    using F=function<void(T&,const T&)>;
    F add,sub;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }
    void resize(int n) { tr.resize(n+2,init); }

    void modify(int pos,T val) {
        if(++pos<=0) return;
        while(pos<tr.size()) add(tr[pos],val),pos+=lowbit(pos);
    }

    void reset(int pos) {
        if(++pos<=0) return;
        while(pos<tr.size()) tr[pos]=init,pos+=lowbit(pos);
    }

    T query(int pos) {
        if(++pos<0) return init;
        T res=init;
        while(pos) add(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }
    
    T range_query(int l,int r) {
        T res=query(r);
        sub(res,query(l-1));
        return res;
    }

    int kth(int k) {
        int pos=0;
        for(int i=__lg(tr.size());i>=0;i--)
            if(pos+(1<<i)<tr.size()&&tr[pos+(1<<i)]<k)
                pos+=1<<i,k-=tr[pos];
        return pos;
    }

    explicit Fenwick(
        int n,
        F add=[](T &x,const T &y) { x+=y; },
        F sub=[](T &x,const T &y) { x-=y; })
        : add(add),sub(sub) {
        resize(n);
    }
};

template<int N,typename T=int> struct SparseTable {
    using F=function<T(T,T)>;
    T st[__lg(N)+1][N];
    F merge;

    void build(int n,function<T(int)> f) {
        for(int i=1;i<=n;i++) st[0][i]=f(i);
        for(int k=1,t=1<<k;t<=n;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=merge(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return merge(st[k][l],st[k][r-(1<<k)+1]);
    }

    SparseTable(F merge=[](T x,T y){ return min(x,y); }) : merge(merge) {}
};
SparseTable<N> sth,sta;

LL cnt[N];
void solve() {
    cin>>SA::s;
    int n=SA::s.size();
    SA::s=" "+SA::s;

    SA::get_sa();
    SA::get_height();

    vector<vector<int>> add(n+2),del(n+2);
    for(int i=1;i<=n;i++) {
        int l=height[i]+1;
        int r=n-sa[i]+1;
        cnt[l]++,cnt[r+1]--;
        add[l].emplace_back(i);
        del[r+1].emplace_back(i);
    }
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];

    int q;
    cin>>q;
    vector<pair<LL,int>> qry(q);
    vector<pair<int,int>> ans(q);
    for(int i=0;i<q;i++) cin>>qry[i].first,qry[i].second=i;
    sort(qry.begin(),qry.end());

    Fenwick<> tr(n);
    sth.build(n, [&](int i) { return height[i]; });
    sta.build(n, [&](int i) { return sa[i]; });
    
    for(int idx=0,i=0;i<q;i++) {
        auto [k,id]=qry[i];
        if(k>cnt[n]) {
            ans[id]={-1,-1};
            continue;
        }
        int len=lower_bound(cnt+1,cnt+n+1,k)-cnt;
        k-=cnt[len-1];

        while(idx<len) {
            idx++;
            for(int x:add[idx]) tr.modify(x, 1);
            for(int x:del[idx]) tr.modify(x, -1);
        }

        int x=tr.kth(k);
        int l=x,r=n;
        while(l<r) {
            int m=(l+r+1)/2;
            if(sth.query(x+1, m)<len) r=m-1;
            else l=m;
        }
        x=sta.query(x, r);

        ans[id]={x,x+len-1};
    }

    for(auto [l,r]:ans) cout<<l<<' '<<r<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}