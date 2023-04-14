#include<iostream>
#include<numeric>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;

struct NODE{
    int l,r,val,dist;
} tr[N];
int fa[N],idx;

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

inline bool cmp(int a,int b){
    if(tr[a].val!=tr[b].val) return tr[a].val<tr[b].val;
    return a<b;
}

int merge(int a,int b){
    if(!a||!b) return a+b;
    if(!cmp(a,b)) swap(a,b);
    tr[a].r=merge(tr[a].r,b);
    if(tr[tr[a].r].dist>tr[tr[a].l].dist) swap(tr[a].l,tr[a].r);
    tr[a].dist=tr[tr[a].r].dist+1;
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    iota(fa+1,fa+1+n,1);
    while(n--){
        int op,a,b;
        cin>>op>>a;
        if(op==2) cin>>b;
        if(op==1) tr[++idx]={0,0,a,1};
        else if(op==2){
            a=findfa(a),b=findfa(b);
            if(a!=b){
                if(!cmp(a,b)) swap(a,b);
                merge(a,b);
                fa[b]=a;
            }
        }
        else if(op==3) cout<<tr[findfa(a)].val<<endl;
        else{
            a=findfa(a);
            int root=merge(tr[a].l,tr[a].r);
            fa[root]=root;
            fa[a]=root;
        }
    }
    return 0;
}