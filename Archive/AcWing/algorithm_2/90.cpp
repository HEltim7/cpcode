#include<iostream>
using namespace std;

typedef long long LL;

LL quick_add(LL a,LL b,LL p){
    LL res=0;
    while (b){
        if(b&1) res=(res+a)%p;
        b>>=1;
        a=(a+a)%p;
    }
    return res;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL a,b,p;
    cin>>a>>b>>p;
    cout<<quick_add(a,b,p);
    return 0;
}