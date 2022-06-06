#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=3e5+10;
LL arr[N],tr[N];
int n;
LL mark[N];

// #define __LOCAL
#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#define cat_arr(...)
#endif

// inline void add(int pos,LL val){
//     while(pos<=n) tr[pos]+=val,pos+=lowbit(pos);
// }

// inline LL query(int pos){
//     LL res=0;
//     while(pos) res+=tr[pos],pos-=lowbit(pos);
//     return res;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>arr[i];

    LL ans=0,cnt=0,pre=0;
    for(int i=n;i>=1;i--){
        // pre-=cnt;
        // cnt-=mark[i];
        arr[i]=max(0LL,arr[i]-pre);

        LL kk=min(1LL*i,k);
        LL t=(arr[i]+kk-1)/kk;
        ans+=t;
        mark[i-kk+1]+=t;
        pre+=kk*t;
        cnt+=t;
        pre-=cnt;
        cnt-=mark[i];

        debug(i,pre,cnt,ans);
        cat_arr(arr,1,n);
        cat_arr(mark,1,n);
    }
    cout<<ans;
    return 0;
}
/////////////////