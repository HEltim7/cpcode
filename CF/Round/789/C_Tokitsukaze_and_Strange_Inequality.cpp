#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=5e3+10;
int tr[2][N];
int arr[N];
int n;

inline void add(int pos,int val,int id) {
    while(pos<=n) tr[id][pos]+=val,pos+=lowbit(pos);
}

inline int qeury(int pos,int id) {
    int res=0;
    while(pos) res+=tr[id][pos],pos-=lowbit(pos);
    return res;
}

inline void init(int pos) {
    memset(tr[0],0,sizeof (int)*(n+1));
    memset(tr[1],0,sizeof (int)*(n+1));
    for(int i=pos;i<=n;i++) add(arr[i],1,1);
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    LL ans=0;
    for(int a=1;a<=n-3;a++) {
        init(a+2);//from a+2 -> n
        LL res=0;
        for(int c=a+2;c<=n-1;c++) {

            int pre=arr[c-1];
            int cur=arr[c];
            res-=qeury(n,0)-qeury(cur,0);
            add(cur,-1,1);
            res+=qeury(pre,1);
            add(pre,1,0);
            if(arr[a]<arr[c]) ans+=res;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}