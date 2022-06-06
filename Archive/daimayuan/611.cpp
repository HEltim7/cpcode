#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

const int N=1e6+100,mod=1e9+7;
LL faet[N],infaet[N];

inline LL qpow(LL a,LL b){
    LL  res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void init(){
    faet[1]=1,faet[0]=1;
    infaet[1]=1,infaet[0]=1;
    for(int i=2;i<N;i++){
        faet[i]=faet[i-1]*i%mod;
        infaet[i]=infaet[i-1]*qpow(i,mod-2)%mod;
    }
}

inline LL get(int a,int b){
    return faet[a]*infaet[a-b]%mod*infaet[b]%mod;
}

LL solve(int x,int y){
    LL res=1;
    vector<pair<int,int>> v;
    for(int i=2;i<=x/i;i++){
        while(x%i==0) {
            x/=i;
            if(v.empty()||v.back().first!=i) v.emplace_back(i,1);
            else v.back().second++;
        }
    }
    if(x>1) v.emplace_back(x,1);
    for(auto [a,b]:v) res=res*get(b+y-1,y-1)%mod;
    return res*qpow(2,y-1)%mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<endl;
    }
    return 0;
}