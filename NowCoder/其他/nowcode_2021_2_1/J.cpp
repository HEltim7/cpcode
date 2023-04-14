#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const long N=1.6e8+10;
const long MO=1e9+7;
int n=N,q,num,in;
int IsPrime[N+1];
bool IsNotPrime[N+1];
bool ate[N+1];
void SearchPrime(){
	memset(IsNotPrime, 0, sizeof(IsNotPrime));
	IsNotPrime[1]=true;
	for(int i=2;i<=n;i++){
		if(!IsNotPrime[i]) IsPrime[++num]=i;
		for(int j=1;i*IsPrime[j]<=n;j++){
			IsNotPrime[i*IsPrime[j]]=true;
			if(i%IsPrime[j]==0) break;
		}
	}
}
int main(){
    SearchPrime();
    long siz,res=1;
    cin>>siz;
    for(long i=1;IsPrime[i]<=siz;i++){
        long tmp=IsPrime[i];
        ate[tmp]=1;
        while(tmp*IsPrime[i]<=siz){
            tmp*=IsPrime[i];
            ate[tmp]=1;
        }
    }
    for(long i=2;i<=siz;i++){
        if(!ate[i]){
            res=(res*i/__gcd(res,i))%MO;
        }
    }
    cout<<res;
    return 0;
}