#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=3e5+10;
LL a[N];
bool isok[N];

inline bool getbit(int x,int bit){
    return (1<<bit)&x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,res=0;
    cin>>n;
    memset(isok,1,sizeof isok);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int bit=30;bit>=0;bit--){
        for(int i=1;i<=n;i++) if(isok[i]) res=i;
        int cnt=0;
        for(int i=1;i<=n;i++) if(getbit(a[i],bit)) cnt++;
        if(n-cnt==cnt||cnt==0||cnt==n) continue;
        bool one=0,zero=0;
        for(int i=1;i<=n;i++){
            if(isok[i]&&getbit(a[i],bit)) one=1;
            else if(isok[i]&&!getbit(a[i],bit)) zero=1;
        }
        if(!one&&!zero) break;
        if(!one||!zero) continue;
        bool flag=n-cnt>cnt;
        for(int i=1;i<=n;i++){
            if(!isok[i]) continue;
            if(flag!=getbit(a[i],bit)) isok[i]=0;
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++) ans+=a[i];
    for(int i=1;i<=n;i++) if(isok[i]) res=i;
    LL tmp=0;
    for(int i=1;i<=n;i++) tmp+=a[i]^a[res];
    cout<<max(ans,tmp);
    return 0;
}