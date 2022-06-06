#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
int a,b;

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int n,m;
    cin>>n;
    while(n--) cin>>m,a+=m;
    cin>>m;
    while(m--) cin>>n,b+=n;
    if(a>b) cout<<"A"<<endl;
    else cout<<"B"<<endl;
    cout<<a<<' '<<b;
    return 0;
}