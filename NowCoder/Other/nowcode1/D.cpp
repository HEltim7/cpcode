#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ull;
int main(){
    ull in,result=1;
    cin>>in;
    for(;in>0;in-=50){
        if(in>=50){
            result=result*898961331%1000000007;//2^50
        }
        else{
            result*=pow(2,in)%1000000007;
        }
    }
}