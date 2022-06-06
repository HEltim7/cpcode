#include<iostream>
#include<iomanip>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a,b,c,x;
    cin>>a>>b>>c>>x;
    if(x<=a) cout<<1;
    else if(x>b) cout<<0;
    else cout<<fixed<<setprecision(12)<<1.*c/(b-a);
    return 0;
}