#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;

struct NODE {
    int l,r,v;
    NODE(int L,int R,int V) : l(L),r(R),v(V) {}
    bool operator< (const NODE &x) const{
        return l<x.l;
    }
};

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

    int assign(int l,int r,int v){
        int res=0;
        auto end=split(r+1),begin=split(l);
        for(auto it=begin;it!=end;it++)
            res+=(v-it->v)*(it->r-it->l+1);
        odt.erase(begin,end);
        odt.insert(NODE(l,r,v));
        return res;
    }

    void init(int l,int r,int v){
        odt.insert(NODE(l,r,v));
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    ODT odt;
    odt.init(1,n,1);
    int sum=n;

    while(q--){
        int op,l,r;
        cin>>l>>r>>op;
        if(op==1) sum+=odt.assign(l,r,0);
        else sum+=odt.assign(l,r,1);
        cout<<sum<<endl;
    }
    return 0;
}