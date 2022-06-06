#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
const int N=1e4+10,M=1e6+10;
struct QUERY{
    int qid;
    int left;
    int right;
    int time;
}Q[N];
struct REPLACE{
    int p;
    int col;
}R[N];
int cnt[N],pen[M],ans[N];
int len,qcnt,rcnt;

inline int getid(int a){
    return a/len;
}

inline void add(int x,int &res){
    if(++cnt[x]==1) res++;
}

inline void del(int x,int &res){
    if(--cnt[x]==0) res--;
}

inline bool cmp(QUERY a,QUERY b){
    int al=getid(a.left),ar=getid(a.right);
    int bl=getid(b.left),br=getid(b.right);
    if(al!=bl) return al<bl;
    else if(ar!=br) return ar<br;
    return a.time<b.time;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>pen[i];
    while(m--){
        int a,b;
        string op;
        cin>>op>>a>>b;
        if(op[0]=='Q') Q[++qcnt]={qcnt,a,b,rcnt};
        else R[++rcnt]={a,b};
    }
    len=max(1,(int)cbrt(n*rcnt));
    sort(Q+1,Q+1+qcnt,cmp);
    for(int q=1,i=1,j=0,k=0,res=0;q<=qcnt;q++){
        int l=Q[q].left,r=Q[q].right,t=Q[q].time,qid=Q[q].qid;
        while(j<r) add(pen[++j],res);
        while(j>r) del(pen[j--],res);
        while(i<l) del(pen[i++],res);
        while(i>l) add(pen[--i],res);
        while(k<t){
            k++;
            if(R[k].p>=i&&R[k].p<=j){
                add(R[k].col,res);
                del(pen[R[k].p],res);
            }
            swap(pen[R[k].p],R[k].col);
        }
        while(k>t){
            if(R[k].p>=i&&R[k].p<=j){
                add(R[k].col,res);
                del(pen[R[k].p],res);
            }
            swap(pen[R[k].p],R[k].col);
            k--;
        }
        ans[qid]=res;
    }
    for(int i=1;i<=qcnt;i++) cout<<ans[i]<<endl;
    return 0;
}