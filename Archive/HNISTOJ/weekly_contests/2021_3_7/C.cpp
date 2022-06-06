#include<bits/stdc++.h>
using namespace std;

int main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    double t,m;
    double sum=0;
    cin>>t>>m;
    if(t<=40){
        sum=t*m;
        cout<<fixed<<setprecision(2)<<sum;
        return 0;
    }
    else{
        sum=40*m;
        t-=40;
        if(t<=10){
            sum+=t*1.5*m;
            cout<<fixed<<setprecision(2)<<sum;
            return 0;
        }
        else{
            sum+=10*1.5*m;
            t-=10;
            sum+=t*2*m;
            cout<<fixed<<setprecision(2)<<sum;
            return 0;
        }
    }
    return 0;
}