//素数筛函数模型
#include<iostream>
#include <cstring>
using namespace std;
int n,num,in;
int IsPrime[6000000];
bool IsNotPrime[100000010];

void SearchPrime(int n){
	memset(IsNotPrime, 0, sizeof(IsNotPrime));
	IsNotPrime[1]=true;
	for(int i=2;i<=n;i++){
		//if(!IsNotPrime[i]) IsPrime[++num]=i;//(可选)统计是第几个素数
		for(int j=1;i*IsPrime[j]<=n;j++){
			IsNotPrime[i*IsPrime[j]]=true;
			if(i%IsPrime[j]==0) break;
		}
	}
}

int main(){
	cin>>n;
	SearchPrime(n);
	return 0;
}