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

using LL=long long;

template<class Info=int,typename I=int> struct SegmentSet {
    struct Seg {
        I l;
        mutable I r;
        mutable Info v;
        bool operator<(const Seg &x) const {
            return l<x.l;
        }
        friend ostream &operator<<(ostream &os,const Seg &x) {
            return os<<"["<<x.l<<"->"<<x.r<<"]";
        }
        Seg(I l,I r={},Info v={}): l(l),r(r),v(v) {}
    };
    set<Seg> st;
    using Iter=typename set<Seg>::iterator;
    
    Iter first_inter(I l,I r) {
        Iter it=--st.upper_bound({l});
        if(it->r<l) it++;
        return it;
    }

    Iter last_inter(I l,I r) {
        return --st.upper_bound({r});
    }

    Iter split(I p) {
        Iter it=st.lower_bound({p});
        if(it->l==p) return it;
        if((--it)->r<p) return st.end();
        auto [l,r,v]=*it;
        st.erase(it);
        st.emplace(l,p-1,v);
        return st.emplace(p,r,v).first;
    }

    Iter merge(Iter it) {
        auto work=[&](Iter lit,Iter rit) {
            if(lit->r+1==rit->l&&lit->v==rit->v) {
                lit->r=rit->r;
                st.erase(rit);
                return true;
            }
            return false;
        };
        auto lit=prev(it),rit=next(it);
        if(work(lit,it)) return work(lit,rit),lit;
        return work(it,rit),it;
    }

    Iter erase(I l,I r) {
        split(l),split(r+1);
        auto lit=first_inter(l,r);
        auto rit=++last_inter(l,r);
        return st.erase(lit,rit);
    }

    Iter insert(I l,I r,Info v) {
        erase(l,r);
        return merge(st.emplace(l,r,v).first);
    }

    I first_uncovered() {
        auto it=st.begin();
        if(it->r+2<next(it)->l) return it->r+2;
        else it=next(it);
        for(;;) {
            if(it->r+1<next(it)->l) return it->r+1;
            else it=next(it);
        }
    }

    SegmentSet(I l,I r) {
        st.emplace(l-2,l-2);
        st.emplace(r+2,r+2);
    }
};

void solve() {
    int n;
    cin>>n;
    SegmentSet<> st(0,1e9+10);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        st.insert(in, in, 0);
    }

    auto ask=[&]() {
        int x=st.first_uncovered();
        cout<<x<<endl;
        st.insert(x, x, 0);
        int in;
        cin>>in;
        assert(in!=-2);
        if(in==-1) return false;
        st.erase(in, in);
        return true;
    };

    while(ask());
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}