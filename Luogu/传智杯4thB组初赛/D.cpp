#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=2e6+10;
int prime[N],pre[N];
bool isprime[N];
int cnt=0;

void getprime(){
    memset(isprime,1,sizeof isprime);
    isprime[1]=0;
    for(int i=2;i<N;i++){
        pre[i]=pre[i-1];
        if(isprime[i]) prime[++cnt]=i,pre[i]++;
        for(int j=1;j<=cnt&&prime[j]<=N/i;j++){
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
}

inline int getbit(int x,int bit){
    return (1<<bit)&x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    getprime();
    int t;
    cin>>t;
    while(t--){
        int x,res=0;
        cin>>x;
        for(int i=0;i<=20;i++){
            if(getbit(x,i)==0) continue;
            int lower=getbit(x,i);
            int upper=(1<<(i+1))-1;
            res+=pre[upper]-pre[max(0,lower-1)];
        }
        cout<<res<<endl;
    }
    return 0;
}