#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=4e5+10,M=2e5+1;
int tr[3][N],pre[N];
int n;

inline void add(int pos){
    pos+=M;
    int aim=pos%3;
    while(pos<=M+n) tr[aim][pos]++,pos+=lowbit(pos);
}

inline int query(int pos){
    pos+=M;
    int aim=pos%3,res=0;
    while(pos>=M-n) res+=tr[aim][pos],pos-=lowbit(pos);
    return res;
}

void solve(){
    LL ans=0;
    cin>>n;
    for(int i=0;i<3;i++)
        for(int j=M-n;j<=M+n;j++) tr[i][j]=0;
    add(0);
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        if(in=='+') pre[i]=pre[i-1]-1;
        else pre[i]=pre[i-1]+1;
        ans+=query(pre[i]);
        add(pre[i]);
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