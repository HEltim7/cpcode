#include<iostream>
using namespace std;

long long QuickPower(long long a,long long b,long long k){
  long long ans=1;
  while(b>0){
    if(b&1){ans=a*ans%k;}
    a=a*a%k;
    b>>=1;
  }
  return ans;
}

int main(){
  long long a,b,k;
  cin>>a>>b>>k;
  cout<<a<<'^'<<b<<" mod "<<k<<'='<<QuickPower(a,b,k)%k;//%k防止b=1，k=1；
  return 0;
}