#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n,m,k;
    cin>>n>>m>>k;
    if(n+m>=1+k) cout<<"YES";
    else cout<<"NO";
    return 0;
}