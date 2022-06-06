#include<bits/stdc++.h>
using namespace std;

int main(){
    double a=2,b=3,c=5,d=1,e=2,f=3,sum=a/d+b/e+c/f;
    for(int i=4;i<=20;i++){
        double t=b+c;
        a=b;
        b=c;
        c=t;
        t=e+f;
        d=e;
        e=f;
        f=t;
        sum+=c/f;
    }
    cout<<fixed<<setprecision(2)<<sum;
    return 0;
}