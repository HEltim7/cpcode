#include<iostream>
using namespace std;

#define endl '\n'
typedef long long ll;

const int N=1e5+10;
int ans,n;
int k,s;
int mod=998244353;
ll feat[N],infeat[N];

ll qpow(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void cmb(){
    feat[0]=1,feat[1]=1;
    infeat[0]=1,infeat[1]=1;
    for(int i=2;i<=1e5;i++){
        feat[i]=feat[i-1]*i%mod;
        infeat[i]=infeat[i-1]*qpow(i,mod-2)%mod;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cmb();
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        s=n;
        int chunk=0;
        for(int i=1;i<=n;i++){
            char in;
            cin>>in;
            if(in=='1') chunk++;
            else{
                s-=chunk%2;
                s-=chunk/2;
                k+=chunk/2;
                chunk=0;
            }
            //特判最后
            if(i==n){
                s-=chunk%2;
                s-=chunk/2;
                k+=chunk/2;
                chunk=0;
            }
        }
        cout<<(feat[s]*infeat[k]%mod)*infeat[s-k]%mod<<endl;
    }
    return 0;
}