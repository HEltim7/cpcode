#include<iostream>
#include<iomanip>
using namespace std;
#define tmp(in) ((2*n-1)*x-fn(in-1)-(n-1)*fn(n-2))/n
double n,x;

double fn(double in){
    if(in==0){return 1;}
    else if(in==1){return x;}
    else {return ((2*in-1)*x-fn(in-1)-(in-1)*fn(in-2))/in;}
}

int main(){
    cin>>n>>x;
    cout<<fixed<<setprecision(2)<<fn(n);
    return 0;
}