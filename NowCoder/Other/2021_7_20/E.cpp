#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;

const int N=1e6+10;
int prime[110];
bool isprime[1100];
int cnt;
int p=100;//非洲人预估值

ll s,e,k;
ll ans;
bool mark[N];//标记该数,可用滚动数组等效代替

void getprime(int n){
    memset(isprime,1,sizeof isprime);
    isprime[1]=0;
    for(int i=1;i<=n;i++){
        if(isprime[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<=n;j++){
            isprime[prime[j]*i]=0;
            if(i%prime[j]==0) break;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    getprime(1000);

    memset(mark,1,sizeof mark);
    cin>>s>>e>>k;
    for(int i=1;i<=p&&k;i++){
        //循环判断整个序列
        for(ll j=s;j<=e&&k;j++){
            if(mark[j-s]&&j%prime[i]==0){
                k--;
                ans+=prime[i];
                mark[j-s]=0;
            }
        }
    }
    cout<<ans;
    return 0;
}