#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e6;
int n,num;
int IsPrime[2001];
bool IsNotPrime[2001];
ll ans[N+1];
void SearchPrime(int n){
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

void sovle(ll in){
	ll tmp=in;
	int i=1;
	while(in>=1&&i<=num){
		if(in%IsPrime[i]==0){
			in/=IsPrime[i];
			ans[tmp]*=10+IsPrime[i];
		}
		else i++;
	}
}

int main(){
    SearchPrime(2000);
	sovle(N);
	cout<<ans[N];
	return 0;
}