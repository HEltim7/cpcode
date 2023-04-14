#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long ull;

int main(){
    string str;
    ull n;
    cin>>str>>n;
    int len=str.length();
    str=' '+str;

    while(n>len){
        ull low=len,up=len*2;
        while(up<n) low*=2,up*=2;
        if(n==low+1) n--;
        else n=n-low-1;
    }
    cout<<str[n];
    return 0;
}