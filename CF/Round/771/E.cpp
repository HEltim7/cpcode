#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10;

LL lazy[N];

struct SEG
{
    int l,r;
    LL v;
} tr[N*4];

struct SGT
{
    void pushdn(int x){
        tr[x<<1].v+=tr[x].v;
        tr[x<<1|1].v+=tr[x].v;
        tr[x].v=0;
    }

    void modify(int x,int l,int r,LL v){
        if(tr[x].l>=l&&tr[x].r<=r) tr[x].v+=v;
        else{
            pushdn(x);
            int mid=tr[x].l+tr[x].r>>1;
            if(l<=mid) modify(x<<1,l,r,v);
            if(r>mid) modify(x<<1|1,l,r,v);
        }
    }

    LL query(int x,int pos){
        if(tr[x].l==tr[x].r) return tr[x].v;
        pushdn(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(pos<=mid) return query(x<<1,pos);
        return query(x<<1|1,pos);
    }

    void build(int x,int l,int r){
        tr[x]={l,r};
        if(l==r) return;
        int mid=l+r>>1;
        build(x<<1,l,mid),build(x<<1|1,mid+1,r);
    }

} sgt;

struct NODE
{
    int l,r,c;
    NODE(int l,int r,int c): l(l),r(r),c(c) {}
    bool operator< (const NODE &x) const{
        return l<x.l;
    }
};

struct ODT
{
    set<NODE> st;
    auto split(int pos){
        auto it=st.lower_bound(NODE(pos,pos,0));
        if(it!=st.end()&&it->l==pos) return it;
        it=prev(it);
        auto [l,r,c]=*it;
        st.erase(it);
        st.insert(NODE(l,pos-1,c));
        return st.insert(NODE(pos,r,c)).first;
    }

    void assign(int l,int r,int c){
        auto end=split(r+1),begin=split(l);
        for(auto it=begin;it!=end;it++){
            auto [L,R,C]=*it;
            sgt.modify(1,L,R,lazy[C]-lazy[c]);
        }
        st.erase(begin,end);
        st.insert(NODE(l,r,c));
    }

    LL query(int pos){
        auto it=prev(st.upper_bound(NODE(pos,pos,0)));
        return sgt.query(1,pos)+lazy[it->c];
    }

    ODT(int l,int r,int c){
        st.insert(NODE(l,r,c));
        sgt.build(1,l,r);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    ODT odt(1,n,1);
    while(q--){
        string op;
        int a,b,c;
        cin>>op;
        if(op=="Color"){
            cin>>a>>b>>c;
            odt.assign(a,b,c);
        }
        else if(op=="Add"){
            cin>>a>>b;
            lazy[a]+=b;
        }
        else{
            cin>>a;
            cout<<odt.query(a)<<endl;
        }
    }
    return 0;
}