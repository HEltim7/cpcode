#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
const int N=200000+10;
typedef long long LL;
LL ans1,ans2,n;
LL tr[N],upper[N],lower[N];

inline void add(int pos){
    while(pos<=n) tr[pos]+=1,pos+=lowbit(pos);
}

inline LL sum(int pos){
    LL res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int in[N];
    for(int i=1;i<=n;i++){
        cin>>in[i];
        add(in[i]);
        upper[i]=sum(n)-sum(in[i]);
        lower[i]=sum(in[i]-1);
    }
    memset(tr,0,sizeof tr);
    for(int i=n;i>=1;i--){
        add(in[i]);
        ans1+=upper[i]*(sum(n)-sum(in[i]));
        ans2+=lower[i]*sum(in[i]-1);
    }
    cout<<ans1<<' '<<ans2;
    return 0;
}