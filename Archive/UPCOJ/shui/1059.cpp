#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int n,s,y;
    cin>>n>>s>>y;
    cout<<n*(s*1./(s+y))<<' '<<n*(y*1./(s+y));
    return 0;
}