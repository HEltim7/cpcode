#include<iostream>
using namespace std;

typedef long long ll;
ll a,b;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    cin>>a>>b;
    if(b%a==0) cout<<a+b;
    else cout<<b-a;
    return 0;
}