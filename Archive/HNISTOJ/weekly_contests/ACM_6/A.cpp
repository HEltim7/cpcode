#include<iostream>
using namespace std;
typedef unsigned long long ull;

int main(){
    ull s=0,a,k;
    cin>>a>>k;
    ull tmp=a;
    for(int i=1;i<=k;i++){
        s+=tmp;
        tmp=tmp*10+a;
    }
    cout<<s;
}