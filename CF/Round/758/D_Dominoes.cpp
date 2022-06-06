#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

const int N=2e5+10,mod=998244353;
LL faet[N],infaet[N];

LL qpow(LL a,LL b){
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

LL get(int a,int b){
    return faet[a]*infaet[a-b]%mod*infaet[b]%mod;
}

int main() {
    // freopen64("in.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    init();
    if(n==1) {
        string in;
        cin>>in;
        if(in=="BB"||in=="WW") cout<<0;
        else cout<<1;
    }
    else {
        LL ans=0,sub=1;
        int bw=1,wb=1;
        int black=n,white=n;
        string in;
        for(int i=1;i<=n;i++) {
            cin>>in;
            if(in=="BB"||in=="WW") sub=0,bw=0,wb=0;
            else if(in=="??") sub=sub*2%mod;
            else if(in=="BW"||in=="B?"||in=="?W") wb=0;
            else if(in=="WB"||in=="W?"||in=="?B") bw=0;

            if(in.front()=='B') black--;
            if(in.front()=='W') white--;
            if(in.back()=='B') black--;
            if(in.back()=='W') white--;
        }
        if(black<0||white<0) {
            cout<<0;
            return 0;
        }
        sub=(sub-bw-wb+mod)%mod;
        ans=(get(black+white,black)-sub+mod)%mod;
        cout<<ans;
    }
    return 0;
}