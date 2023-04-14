#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e5+10;

template<typename T=int> struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) {
        aim+=val;
    }

    void add(int pos,T val) {
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> arr;
    for(char c:s) arr.emplace_back(c=='('?1:-1);

    int offset=n+5;
    Fenwick<LL> maxx(n*2+10),cnt(n*2+10);
    vector<pair<int,int>> minn(1,{0,1});

    LL ans=0,sum=0;
    cnt.add(offset, 1);
    for(int pre=0; int x:arr) {
        pre+=x;
        int tot=1;
        while(minn.size()&&minn.back().first>=pre) {
            auto [x,y]=minn.back();
            tot+=y;
            sum+=1LL*(pre-x)*y;
            minn.pop_back();
        }
        minn.emplace_back(pre,tot);

        ans+=1LL*cnt.query(pre+offset)*pre;
        ans+=maxx.query(n+offset)-maxx.query(pre+offset);
        ans-=sum;
        cnt.add(pre+offset, 1);
        maxx.add(pre+offset, pre);
        sum+=pre;
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

/*
考虑一个合法的括号序列，(看作+1,)看作-1,满足前缀和的最小值>=0，并且总和=0
本质未匹配的括号可以抽象为：
)))...((((
的形式，代价为max(cntl,cntr)-min(cntl,cntr)+min(cntl,cntr)=max(cntl,cntr)
而max(cntl,cntr)=max(-前缀和最小值，后缀最大值)=max(-前缀最小值，总和-前缀最小值)

若当前研究的串是一个子串 [...][)))...((((][...]
则代价应为max(pre[l-1]-min(pre[l,r]),pre[r]-min(pre[l-1,r]))
=max(pre[l-1],pre[r])-min(pre[l-1,r])

从左往右扫，分别计算和维护max与min。
*/