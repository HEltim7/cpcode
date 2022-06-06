#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
double ans;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    double m,v;
    while(cin>>m>>v) ans+=m*v;
    cout<<fixed<<setprecision(1)<<ans;
    return 0;
}