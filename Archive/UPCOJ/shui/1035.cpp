#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
double a,b,c,d;
int n;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    while(cin>>a>>b){
        n++;
        c+=a;
        d+=b;
    }
    cout<<n<<' ';
    cout<<fixed<<setprecision(1)<<c/d;
    return 0;
}