#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10,M=1e6+10;
struct QUERY {
    int l,r,id,blk;
    bool operator< (const QUERY &x) const {
        if(x.blk!=blk) return blk<x.blk;
        return r<x.r;
    }
} q[M];
int color[N],cnt[N],ans[M],res,len;

inline int getblk(int x){
    return x/len;
}

inline void add(int pos){
    if(1&cnt[color[pos]]++) res++;
}

inline void del(int pos){
    if(1&--cnt[color[pos]]) res--;
}

// #define __LOCAL
#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int Q,n;
    cin>>n;
    len=sqrt(n)+1;
    for(int i=1;i<=n;i++) cin>>color[i];
    cin>>Q;
    for(int i=1;i<=Q;i++) cin>>q[i].l>>q[i].r,q[i].id=i,q[i].blk=getblk(q[i].l);
    sort(q+1,q+1+Q);
    for(int i=1,L=1,R=0;i<=Q;i++){
        auto [l,r,id,blk]=q[i];
        while(R<r) add(++R);
        while(R>r) del(R--);
        while(L<l) del(L++);
        while(L>l) add(--L);
        debug(l,r,id,blk);
        debug(L,R,res);
        ans[id]=res;
    }
    for(int i=1;i<=Q;i++) cout<<ans[i]<<endl;
    return 0;
}