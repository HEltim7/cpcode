#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
#define lch tr[x].ch[0]
#define rch tr[x].ch[1]
typedef long long LL;

const int N=1e5+10,INF=0x3f3f3f3f;
struct NODE{
    int ch[2],p,val;
    int size;
    inline void init(int a,int b){
        p=a,val=b,size=1;
    }
} tr[N];
int root,idx,delta;

inline void pushup(int x){
    tr[x].size=tr[lch].size+tr[rch].size+1;
}

inline void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=tr[y].ch[1]==x;
    tr[z].ch[tr[z].ch[1]==y]=x,tr[x].p=z;
    tr[y].ch[k]=tr[x].ch[k^1],tr[tr[y].ch[k]].p=y;
    tr[x].ch[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

inline void splay(int x,int k){
    for(int y,z;(y=tr[x].p)!=k;rotate(x))
        if((z=tr[y].p)!=k) rotate((tr[y].ch[1]==x)^(tr[z].ch[1]==y)?x:y);
    if(!k) root=x;
}

inline int insert(int v){
    int x=root,p=0;
    while(x) p=x,x=tr[x].ch[v>tr[x].val];
    x=++idx;
    if(p) tr[p].ch[v>tr[p].val]=x;
    tr[x].init(p,v);
    splay(x,0);
    return x;
}

inline int getmax(int v){
    int x=root,res;
    while(x){
        if(v<=tr[x].val) res=x,x=lch;
        else x=rch;
    }
    return res;
}

inline int getk(int k){
    int x=root;
    for(;;){
        if(k<=tr[lch].size) x=lch;
        else if(k==tr[lch].size+1) return tr[x].val+delta;
        else k-=tr[lch].size+1,x=rch;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k,total=0;
    cin>>n>>m;
    int L=insert(-INF),R=insert(INF);
    while(n--){
        char op;
        cin>>op>>k;
        if(op=='I'){
            k-=delta;
            if(k+delta>=m) total++,insert(k);
        }
        else if(op=='A') delta+=k;
        else if(op=='S'){
            delta-=k;
            R=getmax(m-delta);
            splay(R,0),splay(L,R);
            tr[L].ch[1]=0;
            pushup(L),pushup(R);
        }
        else cout<<(tr[root].size-2<k?-1:getk(tr[root].size-k))<<endl;
    }
    cout<<total-tr[root].size+2;
    return 0;
}