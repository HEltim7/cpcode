#include<iostream>
using namespace std;
typedef long long ll;
const int N=1e4;
bool isntp[N*N];
int prime[N];
int m,k,cnt,ans;
ll num[30];

void GetPrime(int n){
    isntp[1]=1;
    for(int i=1;i<=n;i++){
        if(!isntp[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt;j++){
            isntp[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}

bool check(ll in){
    if(in==1) return 0;
    for(int i=1;i<=cnt&&in>prime[i];i++){
        if(in%prime[i]==0) return 0;
    }
    return 1;
}

void dfs(int sel,ll sum,int deep){
    if(sel>k||deep>m) return;
    if(sel==k&&deep==m){
        if(check(sum)) ans++;
        return;
    }
    dfs(sel,sum,deep+1);
    dfs(sel+1,sum+num[deep+1],deep+1);
}

int main(){
    cin>>m>>k;
    for(int i=1;i<=m;i++) cin>>num[i];
    GetPrime(N);
    dfs(0,0,0);
    cout<<ans;
    return 0;
}