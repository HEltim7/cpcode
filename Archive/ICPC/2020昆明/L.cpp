#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
typedef long long LL;
const int N=1e6+10;
int tr[N],a[N],ans[N];
int n;

inline void add2(int pos,int val){
    while(pos<=n) tr[pos]=max(tr[pos],val),pos+=lowbit(pos);
}

inline int query2(int pos){
    int res=0;
    while(pos) res=max(res,tr[pos]),pos-=lowbit(pos);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(tr,0,sizeof (int)*(n+1));
        for(int i=1;i<=n;i++) cin>>a[i];
        int maxx=0;
        for(int i=n;i>=1;i--){
            ans[i]=query2(a[i]-1)+1;
            maxx=max(maxx,ans[i]);
            add2(a[i],ans[i]);
        }
        cout<<maxx<<endl;
        for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    }
    return 0;
}