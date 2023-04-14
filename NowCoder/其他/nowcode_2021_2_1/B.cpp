#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long k;
    cin>>k;
    if (k==0)
    {
        cout<<'(';
        return 0;
    }
    int tmp=sqrt(k);
    for(int i=1;i<=tmp;i++) putchar('(');
    for(int i=1;i<tmp;i++) putchar(')');
    while(tmp*tmp<k){
        putchar('(');
        k--;
    }
    putchar(')');
    return 0;
}