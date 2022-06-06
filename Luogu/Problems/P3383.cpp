#include <cstdio>
#include <cstring>
using namespace std;
int n,q,num,in;
int IsPrime[6000000];
bool IsNotPrime[100000010];
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
	scanf("%d%d",&n,&q);
	SearchPrime();
	for(int k=1;k<=q;k++){
		scanf("%d",&in);
		printf("%d\n",IsPrime[in]);
	}
	return 0;
}