#include<iostream>
using namespace std;
const int N=1e4;
const int M=1e8;
bool isntp[M];
int prime[N];
int cnt=0;

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

int main(){
    GetPrime(10000);
    for(int i=1;i<=cnt;i++) cout<<prime[i]<<' ';
    return 0;
}