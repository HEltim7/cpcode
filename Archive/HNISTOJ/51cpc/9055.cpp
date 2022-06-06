#include<iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll in1,in2,in3;

ll QuickPower(ll a,ll b,ll c){
    ll ans=1;
    if(b<=0){return ;}
    a*=a;
    b>>=1;

}

int main(){
    cin>>in1>>in2>>in3;
    cout<<QuickPower(in1,in2,in3);
    return 0;
}