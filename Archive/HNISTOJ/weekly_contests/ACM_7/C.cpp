#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int a,b,num;
int main(){
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        int tmp=i,sum=0;
        while(tmp>0){
            sum+=tmp%10;
            tmp/=10;
        }
        if(sum%5==0)
            num++;
    }
    cout<<num;
}