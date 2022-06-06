#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1<<16;
int res[N];
LL n,m;

void next(int &x){
    int ans=0;
    for(int i=0;i<n;i++){
        if(x&(1<<(i+1)%n)) ans+=x&(1<<i)^(1<<i);
        else ans+=x&(1<<i);
    }
    x=ans;
}

void print(int x){
    for(int i=n-1;i>=0;i--)
        if(x&(1<<i)) cout<<1<<endl;
        else cout<<0<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int now=0,in;
    for(int i=1;i<=n;i++) cin>>in,now+=in<<(n-i);
    for(int i=0;i<=m;i++){
        if(res[now]){
            LL t=i-res[now];
            t=(m-i)%t;
            while(t--) next(now);
            print(now);
            break;
        }
        res[now]=i;
        if(i==m) print(now);
        next(now);
    }
}