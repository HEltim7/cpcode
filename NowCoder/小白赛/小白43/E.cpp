#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=10,mod=1e9+7;
LL num[N],cnt[N][3];
LL ans;

LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void dfs(LL res,int x3,int idx){
    if(idx==10){
        if(x3==0) ans=(ans+res)%mod;
        return;
    }
    for(int i=0;i<=2;i++)
        dfs(res*cnt[idx][i]%mod,(x3+idx*i)%3,idx+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=1;i<=9;i++){
        cin>>num[i];
        for(int j=0;j<=2;j++) cnt[i][j]=num[i]/3;
        if(num[i]%3==1) cnt[i][1]++;
        else if(num[i]%3==2) cnt[i][2]++;
        cnt[i][0]++;
    }
    dfs(1,0,1);
    cout<<ans;
    return 0;
}