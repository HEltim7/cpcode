#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=32767+10,INF=0x3f3f3f3f;

struct NODE{
    int l,r;
    int key,val;
}tr[N];
int root,idx;

inline int new_node(int key){
    tr[++idx].key=key;
    tr[idx].val=rand();
    return idx;
}

inline void zag(int &p){
    int q=tr[p].r;
    tr[p].r=tr[q].l,tr[q].l=p;
    p=q;
}

inline void zig(int &p){
    int q=tr[p].l;
    tr[p].l=tr[q].r,tr[q].r=p;
    p=q;
}

void insert(int &p,int key){
    if(!p) p=new_node(key);
    else if(tr[p].key==key) return;
    else if(key<tr[p].key){
        insert(tr[p].l,key);
        if(tr[tr[p].l].val>tr[p].val) zig(p);
    }
    else{
        insert(tr[p].r,key);
        if(tr[tr[p].r].val>tr[p].val) zag(p);
    }
}

int get_prev(int p,int key){
    if(!p) return -INF;
    if(key<tr[p].key) return get_prev(tr[p].l,key);
    return max(tr[p].key,get_prev(tr[p].r,key));
}

int get_next(int p,int key){
    if(!p) return INF;
    if(key>tr[p].key) return get_next(tr[p].r,key);
    return min(tr[p].key,get_next(tr[p].l,key));
}

void build(){
    root=new_node(-INF);
    tr[root].r=new_node(INF);
    if(tr[root].val<tr[tr[root].r].val) zag(root);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    LL ans=0;
    cin>>n;
    build();
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(i==1) ans+=in;
        else ans+=min(in-get_prev(root,in),get_next(root,in)-in);
        insert(root,in);
    }
    cout<<ans;
    return 0;
}