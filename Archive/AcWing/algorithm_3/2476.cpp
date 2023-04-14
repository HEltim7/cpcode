#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lch tr[x].ch[0]
#define rch tr[x].ch[1]
#define isr(x) (tr[tr[x].p].ch[1]==x)
const int N=5e4+10,M=2e6,INF=0x3f3f3f3f;

struct SEG{
    int l,r,root;
} seg[N*4];

struct NODE
{
    int ch[2],p,val,sz,cnt;
    inline void init(int P,int V){
        p=P,val=V,sz=cnt=1;
    }
} tr[M];

int num[N],idx=2;

inline void pushup(int x){
    tr[x].sz=tr[lch].sz+tr[rch].sz+tr[x].cnt;
}

inline void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=isr(x);
    tr[z].ch[isr(y)]=x,tr[x].p=z;
    tr[y].ch[k]=tr[x].ch[k^1],tr[tr[y].ch[k]].p=y;
    tr[x].ch[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

inline void splay(int &rt,int x,int k){
    for(int y;(y=tr[x].p)!=k;rotate(x))
        if(tr[y].p!=k) rotate(isr(x)^isr(y)?x:y);
    if(!k) rt=x;
}

inline int getk(int x,int k){
    for(;;){
        if(tr[lch].sz>=k) x=lch;
        else if(tr[lch].sz+1==k) return x;
        else k-=tr[lch].sz+1,x=rch;
    }
    return -1;
}

inline int prev(int x,int v){
    int res=-INF,node=1;
    for(;x;){
        if(v<=tr[x].val) x=lch;
        else{
            if(res<=tr[x].val) res=tr[x].val,node=x;
            x=rch;
        }
    }
    return node;
}

inline int nex(int x,int v){
    int res=INF,node=2;
    for(;x;){
        if(v>=tr[x].val) x=rch;
        else {
            if(res>=tr[x].val) res=tr[x].val,node=x;
            x=lch;
        }
    }
    return node;
}

int get_rank(int x,int v){
    if(!x) return 0;
    if(v<=tr[x].val) return get_rank(lch,v);
    else return tr[lch].sz+tr[x].cnt+get_rank(rch,v);
}

void del(int &rt,int x,int v){
    if(!x) return;
    if(tr[x].val==v){
        if(tr[x].cnt>1) tr[x].cnt--;
        else{
            int L=prev(rt,v),R=nex(rt,v);
            splay(rt,L,0),splay(rt,R,L);
            tr[R].ch[0]=0;
            pushup(R),pushup(L);
        }
    }
    else if(tr[x].val>v) del(rt,lch,v);
    else del(rt,rch,v);
    pushup(x);
}

void insert(int &rt,int v){
    int x=rt,p=0;
    while(x&&tr[x].val!=v) p=x,x=tr[x].ch[v>tr[x].val];
    if(!x){
        x=++idx;
        if(p) tr[p].ch[v>tr[p].val]=x;
        tr[x].init(p,v);
    }
    else tr[x].cnt++;
    splay(rt,x,0);
}

void modify(int x,int pos,int aim){
    if(seg[x].l<=pos&&seg[x].r>=pos){
        del(seg[x].root,seg[x].root,num[pos]);
        insert(seg[x].root,aim);
    }
    if(seg[x].l==seg[x].r) return;
    int mid=seg[x].l+seg[x].r>>1;
    if(mid>=pos) modify(x<<1,pos,aim);
    else modify(x<<1|1,pos,aim);
}

int query(int x,int l,int r,int aim){
    if(seg[x].l>=l&&seg[x].r<=r) return get_rank(seg[x].root,aim)-1;
    int res=0,mid=seg[x].l+seg[x].r>>1;
    if(mid>=l) res=query(x<<1,l,r,aim);
    if(mid+1<=r) res+=query(x<<1|1,l,r,aim);
    return res;
}

int get_prev(int x,int l,int r,int v){
    if(seg[x].l>=l&&seg[x].r<=r) return tr[prev(seg[x].root,v)].val;
    int mid=seg[x].l+seg[x].r>>1;
    int res=-INF;
    if(mid>=l) res=max(res,get_prev(x<<1,l,r,v));
    if(mid+1<=r) res=max(res,get_prev(x<<1|1,l,r,v));
    return res;
}

int get_next(int x,int l,int r,int v){
    if(seg[x].l>=l&&seg[x].r<=r) return tr[nex(seg[x].root,v)].val;
    int mid=seg[x].l+seg[x].r>>1;
    int res=INF;
    if(mid>=l) res=min(res,get_next(x<<1,l,r,v));
    if(mid+1<=r) res=min(res,get_next(x<<1|1,l,r,v));
    return res;
}

void build(int x,int l,int r){
    seg[x]={l,r};
    insert(seg[x].root,-INF);
    seg[x].root=idx;
    insert(seg[x].root,INF);
    for(int i=l;i<=r;i++) insert(seg[x].root,num[i]);
    if(l==r) return;
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    tr[1].val=-INF;tr[2].val=INF;
    while(m--){
        int op,a,b,c;
        cin>>op>>a>>b;
        if(op!=3) cin>>c;
        if(op==1) cout<<query(1,a,b,c)+1<<endl;
        else if(op==2){
            int l=1,r=1e8;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(query(1,a,b,mid)+1<=c) l=mid;
                else r=mid-1;
            }
            cout<<l<<endl;
        }
        else if(op==3){
            modify(1,a,b);
            num[a]=b;
        }
        else if(op==4) cout<<get_prev(1,a,b,c)<<endl;
        else if(op==5) cout<<get_next(1,a,b,c)<<endl;
    }
    return 0;
}

//////////////////////

/*
1. 查询整数 x 在区间 [l,r] 内的排名。
分解为若干区间
每个区间求出比x小的值的数量
答案=sum+1

2. 查询区间 [l,r] 内排名为 k 的值。
分解为若干区间
二分答案，重复1

3. 将 pos 位置的数修改为 x。
递归修改含有pos的所有区间
每个区间找到该值，如果cnt==1,splay后修改
否则cnt--

4. 查询整数 x 在区间 [l,r] 内的前驱(前驱定义为小于 x，且最大的数)。
分解为若干区间
每个区间查找前驱
答案取max

5. 查询后继
同4，答案取min
*/