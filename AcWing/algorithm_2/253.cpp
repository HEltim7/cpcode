#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,INF=0x3f3f3f3f;

struct NODE{
    int l,r;
    int key,val;
    int cnt,size;
}tr[N];
int root,idx;

inline int new_node(int key){
    tr[++idx].key=key;
    tr[idx].val=rand();
    tr[idx].cnt=tr[idx].size=1;
    return idx;
}

inline void pushup(int id){
    tr[id].size=tr[tr[id].l].size+tr[tr[id].r].size+tr[id].cnt;
}

inline void zag(int &p){
    int q=tr[p].r;
    tr[p].r=tr[q].l,tr[q].l=p;
    pushup(p),pushup(q);
    p=q;
}

inline void zig(int &p){
    int q=tr[p].l;
    tr[p].l=tr[q].r,tr[q].r=p;
    pushup(p),pushup(q);
    p=q;
}

void insert(int &p,int key){
    if(!p) p=new_node(key);
    else if(tr[p].key==key) tr[p].cnt++;
    else if(key<tr[p].key) {
        insert(tr[p].l,key);
        if(tr[tr[p].l].val>tr[p].val) zig(p);
    }
    else {
        insert(tr[p].r,key);
        if(tr[tr[p].r].val>tr[p].val) zag(p);
    }
    pushup(p);
}

void erase(int &p,int key){
    if(!p) return;
    if(tr[p].key==key){
        if(tr[p].cnt>1) tr[p].cnt--;
        else if(!tr[p].l&&!tr[p].r) p=0;
        else if(!tr[p].l||tr[tr[p].r].val>tr[tr[p].l].val)
            zag(p),erase(tr[p].l,key);
        else zig(p),erase(tr[p].r,key);
    }
    else if(key<tr[p].key) erase(tr[p].l,key);
    else erase(tr[p].r,key);
    pushup(p);
}

int get_rank(int p,int key){
    if(!p) return INF;
    if(tr[p].key==key) return tr[tr[p].l].size+1;
    else if(key<tr[p].key) return get_rank(tr[p].l,key);
    return tr[tr[p].l].size+tr[p].cnt+get_rank(tr[p].r,key);
}

int get_key(int p,int rank){
    if(!p) return INF;
    int lrank=tr[tr[p].l].size;
    if(rank<=lrank) return get_key(tr[p].l,rank);
    else if(rank<=lrank+tr[p].cnt) return tr[p].key;
    return get_key(tr[p].r,rank-lrank-tr[p].cnt);
}

int get_prev(int p,int key){
    if(!p) return -INF;
    if(tr[p].key>=key) return get_prev(tr[p].l,key);
    return max(tr[p].key,get_prev(tr[p].r,key));
}

int get_next(int p,int key){
    if(!p) return INF;
    if(tr[p].key<=key) return get_next(tr[p].r,key);
    return min(tr[p].key,get_next(tr[p].l,key));
}

void build(){
    root=new_node(-INF);
    tr[root].r=new_node(INF);
    pushup(root);
    if(tr[1].val<tr[2].val) zag(root);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    build();
    while(n--){
        int op,x;
        cin>>op>>x;
        if(op==1) insert(root,x);
        else if(op==2) erase(root,x);
        else if(op==3) cout<<get_rank(root,x)-1<<endl;
        else if(op==4) cout<<get_key(root,x+1)<<endl;
        else if(op==5) cout<<get_prev(root,x)<<endl;
        else cout<<get_next(root,x)<<endl;
    }
    return 0;
}