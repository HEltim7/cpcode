#include<iostream>
using namespace std;
int n,in,start;
int safeants,illants,ants;

int main(){
    cin>>n;
    cin>>start;
    while(--n){
        cin>>in;
        if(in*start>0&&start>in) ants++;
        else if(in*start<0&&start<-in) illants++;
    }
    if(illants>0) cout<<ants+illants+1;
    else cout<<1;
    return 0;
}