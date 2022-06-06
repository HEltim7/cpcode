#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    double t,m;
    double ans=0;
    cin>>t>>m;
    if(t<=40){
        ans=t*m;
    }
    else if(t<=50){
        ans+=40*m;
        ans+=(t-40)*m*1.5;
    }
    else{
        ans+=40*m;
        ans+=10*m*1.5;
        ans+=(t-50)*m*2;
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}