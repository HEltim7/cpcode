#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int M=2e5+10;
LL a[M],sum[M*40],lazy[M*40];
int ls[M*40],rs[M*40],root[M],idx;
LL rowval[M],rowtim[M];

void pushup(int l,int r,int rt){
    sum[rt] = sum[ls[rt]] + sum[rs[rt]] + 1LL*(r-l+1)*lazy[rt];
}

void build(int l,int r,int &rt){
    rt = ++idx;lazy[rt]  = 0; sum[rt] = 0;
    if(l == r){
        sum[rt] = a[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(l,m,ls[rt]);
    build(m+1,r,rs[rt]);
    pushup(l,r,rt);
}

void update(int old,int &rt,int L,int R,LL c,int l,int r){
    rt = ++idx; ls[rt] = ls[old]; rs[rt] = rs[old];
    sum[rt] = sum[old]; lazy[rt] = lazy[old];
    if(L <= l&&R >= r){
        sum[rt] += 1LL*(r-l+1)*c;
        lazy[rt] += c;
        return ;
    }
    int m = (l + r) >> 1;
    if(L <= m) update(ls[old],ls[rt],L,R,c,l,m);
    if(R > m) update(rs[old],rs[rt],L,R,c,m+1,r);
    pushup(l,r,rt);
}

LL query(int L,int R,int l,int r,int rt){
    if(L <= l&&R >= r)  return sum[rt];
    int m = (l + r) >> 1;
    LL ans = 1LL*(R-L+1)*lazy[rt];
    if(R <= m) ans += query(L,R,l,m,ls[rt]);
    else if(L > m) ans += query(L,R,m+1,r,rs[rt]);
    else{  
        ans += query(L,m,l,m,ls[rt]);   
        ans += query(m+1,R,m+1,r,rs[rt]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m,q;
    cin>>n>>m>>q;

    build(1,m,root[0]);
    int tim=0;
    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int l,r,x;
            cin>>l>>r>>x;
            update(root[tim],root[tim+1],l,r,x,1,m);
            tim++;
        }
        else if(op==2) {
            int r,x;
            cin>>r>>x;
            rowval[r]=x;
            rowtim[r]=tim;
        }
        else if(op==3) {
            int r,c;
            cin>>r>>c;
            LL val=query(c,c,1,m,root[tim])-query(c,c,1,m,root[rowtim[r]])+rowval[r];
            cout<<val<<endl;
        }
    }
    return 0;
}