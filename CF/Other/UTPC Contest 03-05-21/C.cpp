#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n,m,s,t;
    cin>>m>>n>>s>>t;
    int order=0;
    order=min(m/s,n/t);
    cout<<s*order<<' '<<t*order;
    return 0;
}