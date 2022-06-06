#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=2e5+10;
int c[N],a[N],tr[N];
int n;

inline void add(int pos){
    while(pos<=n) tr[pos]+=1,pos+=lowbit(pos);
}

inline int query(int pos){
    int res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

void solve(){
    memset(tr,0,sizeof (int)*(n+1));
    LL sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i],sum+=c[i];
    int one=sum/n;
    for(int i=n;i>=1;i--){
        int l=i+1,r=n;
        while(l<r){
            int mid=l+r+1>>1;
            int len=mid-i;
            if(len-query(mid)<one) l=mid;
            else r=mid-1;
        }
        if(l==i+1&&a[l]==0&&one==1||l>n) l=i;
        if(one){
            int t=c[i]-(l-i+1);
            if(t>0) a[i]=1,add(i);
            else a[i]=0;
        }
        else a[i]=0;
        one-=a[i];
    }
    a[1]=one>0;
    for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}