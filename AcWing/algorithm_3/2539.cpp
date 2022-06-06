#include<iostream>
using namespace std;

#define endl '\n'
#define lch tr[x].ch[0]
#define rch tr[x].ch[1]
#define isr(x) (tr[tr[x].p].ch[1]==x)
typedef long long LL;
const int N=1e5+10;

struct NODE
{
    int ch[2],p,v;
    int rev,sum;
} tr[N];
int n,m;
int stk[N];

///////splay///////

//判断x是否为splay的根
inline bool isroot(int x){
    return tr[tr[x].p].ch[0]!=x&&tr[tr[x].p].ch[1]!=x;
}

//翻转左右子树
inline void pushrev(int x){
    swap(lch,rch);
    tr[x].rev^=1;
}

inline void pushup(int x){
    tr[x].sum=tr[lch].sum^tr[rch].sum^tr[x].v;
}

inline void pushdn(int x){
    if(tr[x].rev) pushrev(lch),pushrev(rch),tr[x].rev=0;
}

inline void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=isr(x);
    if(!isroot(y)) tr[z].ch[isr(y)]=x;
    tr[x].p=z;
    tr[y].ch[k]=tr[x].ch[k^1],tr[tr[y].ch[k]].p=y;
    tr[x].ch[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

inline void splay(int x){
    int top=0,fa=x;
    stk[++top]=fa;
    while(!isroot(fa)) stk[++top]=fa=tr[fa].p;
    while(top) pushdn(stk[top--]);
    for(int y;!isroot(x);rotate(x))
        if(!isroot(y=tr[x].p)) rotate(isr(x)^isr(y)?x:y);
}

///////LCT///////

//打通从根到x的实边路径，相冲的边设为虚边，同时x变为splay的根
inline void access(int x){
    int z=x;
    for(int y=0;x;y=x,x=tr[x].p){
        splay(x);
        rch=y,pushup(x);
    }
    splay(z);
}

//将x变为LCT的根节点，即翻转splay的中序遍历
inline void makeroot(int x){
    access(x);
    pushrev(x);//access完后，x为splay的根，直接pushrev
}

//寻找x在LCT中的根节点,同时将此节点变为splay的根
inline int findroot(int x){
    access(x);
    while(lch) pushdn(x),x=lch;
    splay(x);
    return x;
}

//提取出从x到y的实边路径，同时y变为splay的根节点
inline void split(int x,int y){
    makeroot(x);
    access(y);
}

//如果x,y不联通，则加入x-y这条虚边
inline void link(int x,int y){
    makeroot(x);
    if(findroot(y)!=x) tr[x].p=y;
}

//如果x,y联通，则删除x-y这条边
inline void cut(int x,int y){
    makeroot(x);
    if(findroot(y)==x&&rch==y&&!tr[y].ch[0]){
        rch=tr[y].p=0;
        pushup(x);
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>tr[i].v;
    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==0){
            split(x,y);
            cout<<tr[y].sum<<endl;
        }
        else if(op==1) link(x,y);
        else if(op==2) cut(x,y);
        else {
            splay(x);
            tr[x].v=y;
            pushup(x);
        }
    }
    return 0;
}