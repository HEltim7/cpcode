#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long N=4e6;
const long M=1e9+7;
int n,num;
int IsPrime[2001];
bool IsNotPrime[2001];
ll ans[N+1];
ll f[N+1];

ll power(ll in,ll level){
    ll tmp=in;
    for(int i=1;i<level;i++){
        tmp=tmp*in%M;
    }
    return tmp;
}

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
    struct Ia{
        ll val;
        int level;
    } key[100];
    ll k=0;
	ll i=1,ad=10,addlevel=1;
	while(in>1&&i<=num){
		if(in%IsPrime[i]==0){
			in/=IsPrime[i];
            while (IsPrime[i]>ad){
                ad*=10;
                addlevel+=1;
            }
			key[++k].val=IsPrime[i];
            for(int j=1;j<k;j++){
                key[j].level+=addlevel;
            }
            key[k].level=1;
            ad=10,addlevel=1;
		}
		else i++;
	}
    if(in>1){
        while (in>ad){
            ad*=10;
            addlevel+=1;
        }
        for(int j=1;j<k;j++){
            key[j].level+=addlevel;
        }
		key[++k].val=in;
        key[k].level=1;
    }
    for(int i=1;i<=k;i++){
        ans[tmp]+=(key[i].val*power(10,key[i].level-1))%M;
    }
    ans[tmp]%=M;
}

int main(){
    SearchPrime(2000);
    long what;
    cin>>what;
    long l=1;
    while(l+10000<what){
        l+=10000;
    }
    for(int i=1;i<=what;i++){
        sovle(i);
        f[i]=(f[i-1]+ans[i])%M;
    }
    cout<<f[what];
	return 0;
}