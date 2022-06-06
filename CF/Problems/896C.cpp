#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;

struct NODE {
    int l,r;
    mutable LL v;
    NODE(int L,int R,LL V) : l(L),r(R),v(V) {}
    bool operator< (const NODE &x) const{
        return l<x.l;
    }
};

inline LL qpow(LL a,LL b,LL mod){
    LL res=1;
    a%=mod;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

struct ODT {
    set<NODE> odt;
    auto split(int pos){
        auto it=odt.lower_bound(NODE(pos,pos,0));
        if(it!=odt.end()&&it->l==pos) return it;
        it=prev(it);
        auto [l,r,v]=*it;
        odt.erase(it);
        odt.insert(NODE(l,pos-1,v));
        return odt.insert(NODE(pos,r,v)).first;
    }

    void assign(int l,int r,LL v){
        auto end=split(r+1),begin=split(l);
        odt.erase(begin,end);
        odt.insert(NODE(l,r,v));
    }

    void init(int l,int r,LL v){
        odt.insert(NODE(l,r,v));
    }

    void add(int l,int r,LL v){
        auto end=split(r+1),begin=split(l);
        for(auto it=begin;it!=end;it++) it->v+=v;
    }

    LL kth(int l,int r,int k){
        auto end=split(r+1),begin=split(l);
        vector<pair<LL,int>> res;
        for(auto it=begin;it!=end;it++)
            res.emplace_back(it->v,it->r-it->l+1);
        sort(res.begin(),res.end());
        for(auto [val,len]:res){
            k-=len;
            if(k<=0) return val;
        }
        return -1;
    }

    LL cal(int l,int r,LL x,LL y){
        LL res=0;
        auto end=split(r+1),begin=split(l);
        for(auto it=begin;it!=end;it++)
            res=(res+(it->r-it->l+1)*qpow(it->v,x,y)%y)%y;
        return res;
    }
};

inline LL rnd(LL &seed){
    LL ret=seed;
    seed=(seed*7+13)%1000000007;
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    LL seed,vmax;
    cin>>n>>m>>seed>>vmax;
    ODT odt;
    odt.init(1,n,0);
    for(int i=1;i<=n;i++)
        odt.assign(i,i,rnd(seed)%vmax+1);
    while(m--){
        int op,l,r;
        LL x,y;
        op=rnd(seed)%4+1;
        l=rnd(seed)%n+1;
        r=rnd(seed)%n+1;
        if(l>r) swap(l,r);
        if(op==3) x=rnd(seed)%(r-l+1)+1;
        else x=rnd(seed)%vmax+1;
        if(op==4) y=rnd(seed)%vmax+1;

        if(op==1) odt.add(l,r,x);
        else if(op==2) odt.assign(l,r,x);
        else if(op==3) cout<<odt.kth(l,r,x)<<endl;
        else cout<<odt.cal(l,r,x,y)<<endl;
    }
    return 0;
}