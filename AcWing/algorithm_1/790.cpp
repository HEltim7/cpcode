#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double num,ans;
const double N=1e-7;

int main(){
    cin>>num;
    for(double i=-22,j=22,mid=(i+j)/2;i<=j;mid=(i+j)/2){
        double res=num-pow(mid,3);
        if(abs(res)<N){
            cout<<fixed<<setprecision(6)<<mid;
            return 0;
        }
        if(res<0) j=mid;
        else i=mid;
    }
    return 0;
}