#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n=1000000,num;
int IsPrime[600000];
bool IsNotPrime[1000010];//筛到更高估计超时（除非打表
long long in;
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

int getans(){
    int ans=0;
    for(int i=1;in!=1;i++){
		if(IsPrime[i]>sqrt(in)){//此时n必为大于sqrt(n)的质数
			ans++;
			break;
		}
        for(;in%IsPrime[i]==0;ans++){
            in/=IsPrime[i];
        }
    }
    return ans;
}

int main(){
	SearchPrime();
    while(scanf("%lld",&in)!=EOF){
        printf("%d\n",getans());
    }
	return 0;
}