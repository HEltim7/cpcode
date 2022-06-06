#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
int n,m,len;
LL idx[N],cnt[N],ans[N];
struct QUERY
{
    int l,r,id;
}Q[N];
vector<int> num;

inline int getid(int x){
    return x/len;
}

inline bool cmp(QUERY a,QUERY b){
    int al=getid(a.l),bl=getid(b.l);
    if(al!=bl) return al<bl;
    return a.r<b.r;
}

inline void add(int x,LL &res){
    cnt[x]++;
    res=max(res,cnt[x]*num[x]);
}

inline void del(int x){
    cnt[x]--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    len=sqrt(n)+1;
    for(int i=1;i<=n;i++){
        cin>>idx[i];
        num.push_back(idx[i]);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    num.shrink_to_fit();
    for(int i=1;i<=n;i++)
        idx[i]=lower_bound(num.begin(),num.end(),idx[i])-num.begin();

    for(int i=1;i<=m;i++){
        cin>>Q[i].l>>Q[i].r;
        Q[i].id=i;
    }
    sort(Q+1,Q+1+m,cmp);
    LL res=0;
    int i,j;
    for(int q=1;q<=m;q++){
        auto &[l,r,id]=Q[q];
        int cut=(getid(l)+1)*len;//分割点
        if(getid(l)!=getid(Q[q-1].l)||q==1){
            memset(cnt,0,sizeof cnt);
            res=0;
            i=cut,j=cut-1;
        }
        //同块，直接暴
        if(getid(l)==getid(r)){
            res=0;
            for(int k=l;k<=r;k++) add(idx[k],res);
            ans[id]=res;
            for(int k=l;k<=r;k++) del(idx[k]);
        }
        //跨块，l段直接暴，r段递增
        else{
            while(j<r) add(idx[++j],res);
            LL backup=res;
            while(i>l) add(idx[--i],res);
            ans[id]=res;
            while(i<cut) del(idx[i++]);
            res=backup;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    return 0;
}