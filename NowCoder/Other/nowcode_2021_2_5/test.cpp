#include<bits/stdc++.h>
using namespace std;
const long M=1e9+7;
typedef long long ll;
ll power(ll in,ll level){
    ll tmp=in;
    for(int i=1;i<level;i++){
        tmp=tmp*in%M;
    }
    return tmp;
}
int main(){
    long long out;
    for(int i=10;i<=10;i++) cout<<power(10,i)<<endl;
    cout<<10000000000%M;
}