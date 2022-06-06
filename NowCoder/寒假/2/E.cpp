#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n;
    cin>>n;
    if(n<=1) cout<<"0 0";
    else if(n<=2) cout<<"1 1";
    else if(n&1) cout<<n-1<<' '<<n*(n-1)/2;
    else {
        LL tmp=(n-1)/2;
        cout<<n-1<<' '<<tmp*n+1;
    }
    return 0;
}