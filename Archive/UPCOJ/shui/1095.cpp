#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
double ans;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int n;
    double t;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>t,ans+=t*t+t-42;
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}