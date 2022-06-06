#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL x,n;
    cin>>x>>n;
    if(x<n) cout<<x;
    else cout<<x*n;
    return 0;
}