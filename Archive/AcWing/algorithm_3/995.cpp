#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lch tr[x].ch[0]
#define rch tr[x].ch[1]
#define isr(x) (tr[tr[x].p].ch[1]==x)
typedef long long LL;
const int N=5e5+10,INF=0x3f3f3f3f;

struct NODE{
    int ch[2],p,val,sz;
    int ms,lmax,rmax,sum;
    bool rev,same;
    inline void init(int P,int V){
        p=P,val=V,sz=1;
        sum=ms=V,lmax=rmax=max(V,0);
        ch[0]=ch[1]=rev=same=0;//清理dirt内存
    }
} tr[N];
int cache[N],mem[N],idx,root;

inline void pushup(int x){
    tr[x].sz=tr[lch].sz+tr[rch].sz+1;
    tr[x].sum=tr[lch].sum+tr[rch].sum+tr[x].val;
    tr[x].lmax=max(tr[lch].lmax,tr[lch].sum+tr[x].val+tr[rch].lmax);
    tr[x].rmax=max(tr[rch].rmax,tr[rch].sum+tr[x].val+tr[lch].rmax);
    tr[x].ms=max({tr[lch].ms,tr[rch].ms,tr[lch].rmax+tr[x].val+tr[rch].lmax});
}

inline void update(int x,bool rev,bool same,int c){
    if(same){
        tr[x].val=c;
        tr[x].sum=tr[x].sz*tr[x].val;
        if(c>0) tr[x].ms=tr[x].lmax=tr[x].rmax=tr[x].sz*c;
        else tr[x].ms=c,tr[x].lmax=tr[x].rmax=0;
        tr[x].same=same;
    }
    else if(rev) swap(tr[x].lmax,tr[x].rmax),swap(lch,rch),tr[x].rev^=rev;
}

inline void pushdn(int x){
    if(lch) update(lch,tr[x].rev,tr[x].same,tr[x].val);
    if(rch) update(rch,tr[x].rev,tr[x].same,tr[x].val);
    tr[x].rev=tr[x].same=0;
}

inline void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=isr(x);
    tr[z].ch[isr(y)]=x,tr[x].p=z;
    tr[y].ch[k]=tr[x].ch[k^1],tr[tr[y].ch[k]].p=y;
    tr[x].ch[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

inline void splay(int x,int k){
    for(int y;(y=tr[x].p)!=k;rotate(x))
        if(tr[y].p!=k) rotate(isr(x)^isr(y)?x:y);
    if(!k) root=x;
}

inline int getk(int k){
    int x=root;
    for(;;){
        pushdn(x);
        if(tr[lch].sz>=k) x=lch;
        else if(tr[lch].sz+1==k) return x;
        else k-=tr[lch].sz+1,x=rch;
    }
    return -1;
}

int build(int l,int r,int fa){
    int mid=l+r>>1;
    int x=mem[idx--];
    tr[x].init(fa,cache[mid]);
    if(l<=mid-1) lch=build(l,mid-1,x);
    if(mid+1<=r) rch=build(mid+1,r,x);
    pushup(x);
    return x;
}

void recycle(int x){
    mem[++idx]=x;
    if(lch) recycle(lch);
    if(rch) recycle(rch);
}

/////////////

inline void insert(int posi,int tot){
    int L=getk(posi),R=getk(posi+1);
    splay(L,0),splay(R,L);
    tr[R].ch[0]=build(1,tot,R);
    splay(tr[R].ch[0],0);
}

inline void del(int posi,int tot){
    int L=getk(posi-1),R=getk(posi+tot);
    splay(L,0),splay(R,L);
    recycle(tr[R].ch[0]);
    tr[R].ch[0]=0;
    pushup(R),pushup(L);
}

inline void make_same(int posi,int tot,int c){
    int L=getk(posi-1),R=getk(posi+tot);
    splay(L,0),splay(R,L);
    update(tr[R].ch[0],0,1,c);
    pushup(R),pushup(L);
}

inline void reverse(int posi,int tot){
    int L=getk(posi-1),R=getk(posi+tot);
    splay(L,0),splay(R,L);
    update(tr[R].ch[0],1,0,0);
    pushup(R),pushup(L);
}

inline int get_sum(int posi,int tot){
    int L=getk(posi-1),R=getk(posi+tot);
    splay(L,0),splay(R,L);
    return tr[tr[R].ch[0]].sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<N;i++) mem[++idx]=i;
    for(int i=2;i<=n+1;i++) cin>>cache[i];
    tr[0].ms=cache[1]=cache[n+2]=-INF;//tr[0].ms必须置为无穷
    root=build(1,n+2,0);
    while(m--){
        string op;
        int posi,tot,c;
        cin>>op;
        if(op=="INSERT"){
            cin>>posi>>tot;
            for(int i=1;i<=tot;i++) cin>>cache[i];
            insert(posi+1,tot);
        }
        else if(op=="DELETE") cin>>posi>>tot,del(posi+1,tot);
        else if(op=="MAKE-SAME") cin>>posi>>tot>>c,make_same(posi+1,tot,c);
        else if(op=="REVERSE") cin>>posi>>tot,reverse(posi+1,tot);
        else if(op=="GET-SUM") cin>>posi>>tot,cout<<get_sum(posi+1,tot)<<endl;
        else cout<<tr[root].ms<<endl;
    }
    return 0;
}