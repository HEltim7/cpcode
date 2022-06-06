#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int m;
    while(cin>>m&&m){
        int a=0,b=0,c=0;
        c=m/5;
        m%=5;
        b=m/2;
        m%=2;
        a=m;
        cout<<a<<' '<<b<<' '<<c<<endl;
    }
    return 0;
}