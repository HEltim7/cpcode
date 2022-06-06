#include<bits/stdc++.h>
using namespace std;

int main(){
    long a,b;
    cin>>a>>b;
    if(b==0){
        cout<<"error";
        return 0;
    }
    if(a%b==0){
        cout<<setprecision(0)<<a/b;
        return 0;
    }
    else
    {
        cout<<fixed<<setprecision(2)<<a*1./b;
    }
    return 0;
}