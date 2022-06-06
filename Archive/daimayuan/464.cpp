#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e5+10;

struct QUERY {
    int L,R,H,id;
    bool operator< (const QUERY &x) const {return H<x.H;}
} q[N];
PII num[N];
int tr[N],ans[N],n;

inline void add(int pos){
    while(pos<=n) tr[pos]++,pos+=lowbit(pos);
}

inline int query(int pos){
    int res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T,Q;
    cin>>T;
    while(T--){
        cin>>n>>Q;
        memset(tr,0,sizeof (int)*(n+1));
        for(int i=1;i<=n;i++) cin>>num[i].first,num[i].second=i;
        for(int i=1;i<=Q;i++) cin>>q[i].L>>q[i].R>>q[i].H,q[i].id=i;
        sort(num+1,num+1+n);
        sort(q+1,q+1+Q);
        int idx=1;
        for(int i=1;i<=Q;i++){
            auto [l,r,h,id]=q[i];
            while(num[idx].first<=h&&idx<=n) add(num[idx++].second);
            ans[id]=query(r)-query(l-1);
        }
        for(int i=1;i<=Q;i++) cout<<ans[i]<<" \n"[i==Q];
    }
    return 0;
}