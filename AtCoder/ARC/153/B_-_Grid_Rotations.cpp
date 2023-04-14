#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;

struct NODE{
    int c[2],p,val;
    int size,flag;
    void init(int a,int b){
        p=a,val=b,size=1;
    }
}tr[N];
int root,idx;

void pushup(int x){
    auto &t=tr[x];
    t.size=tr[t.c[0]].size+tr[t.c[1]].size+1;
}

void pushdn(int x){
    auto &t=tr[x];
    if(t.flag){
        swap(t.c[0],t.c[1]);
        tr[t.c[0]].flag^=1;
        tr[t.c[1]].flag^=1;
        t.flag=0;
    }
}

void rotate(int x){
    int y=tr[x].p,z=tr[y].p;
    int k=tr[y].c[1]==x;
    tr[z].c[tr[z].c[1]==y]=x,tr[x].p=z;
    tr[y].c[k]=tr[x].c[k^1],tr[tr[y].c[k]].p=y;
    tr[x].c[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

void splay(int x,int k){
    for(int y,z;(y=tr[x].p)!=k;rotate(x))
        if((z=tr[y].p)!=k) rotate((x==tr[y].c[1])^(y==tr[z].c[1])?x:y);
    if(!k) root=x;
}

int getk(int k){
    int x=root;
    for(;;){
        pushdn(x);
        if(tr[tr[x].c[0]].size>=k) x=tr[x].c[0];
        else if(tr[tr[x].c[0]].size+1==k) return x;
        else k-=tr[tr[x].c[0]].size+1,x=tr[x].c[1];
    }
    return -1;
}

void insert(int v){
    int x=root,p=0;
    while(x) p=x,x=tr[x].c[v>tr[x].val];
    x=++idx;
    if(p) tr[p].c[v>tr[p].val]=x;
    tr[x].init(p,v);
    splay(x,0);
}

void output(int x,vector<int> &arr,int n){
    pushdn(x);
    auto &t=tr[x];
    if(t.c[0]) output(t.c[0],arr,n);
    if(t.val>=1&&t.val<=n) arr.push_back(t.val);
    if(t.c[1]) output(t.c[1],arr,n);
}

string grid[N],ans[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>grid[i],grid[i]=" "+grid[i];

    vector<pair<int,int>> op;
    int q;
    cin>>q;
    while(q--) {
        int a,b;
        cin>>a>>b;
        op.emplace_back(a,b);
    }
    for(int i=0;i<=n+1;i++) insert(i);
    debug(op);

    auto rev=[](int l,int r) {
        // if(l==r) return;
        debug(l,r);
        l=getk(l),r=getk(r+2);
        splay(l,0),splay(r,l);
        tr[tr[r].c[0]].flag^=1;
    };

    vector<int> row(1),col(1);
    for(auto [a,b]:op) {
        int l=1,r=a;
        rev(l,r);
        l=a+1,r=n;
        rev(l,r);
    }
    output(root, row, n);
    debug(row);
    
    memset(tr,0,sizeof tr);
    root=idx=0;
    for(int i=0;i<=m+1;i++) insert(i);
    for(auto [a,b]:op) {
        int l=1,r=b;
        rev(l,r);
        l=b+1,r=m;
        rev(l,r);
    }
    output(root, col, m);
    debug(col);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            cout<<grid[row[i]][col[j]];
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}