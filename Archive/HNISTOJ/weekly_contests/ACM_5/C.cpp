//暴力算法
#include<bits/stdc++.h>
using namespace std;
#define fn(x) a*pow(x,3)+b*pow(x,2)+c*x+d
int main(){
    double a,b,c,d,x;
    int ansFinded=0;
    cin>>a>>b>>c>>d;
    for(x=-100;ansFinded<3;x+=0.01){
        if(fabsl(fn(x))<=0.00001){
            ansFinded++;
            cout<<fixed<<setprecision(2)<<x<<' ';
            continue;
        }
    }
    return 0;
}