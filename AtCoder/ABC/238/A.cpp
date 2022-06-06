#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n;
    cin>>n;
    if(n==1||n>=5) cout<<"Yes";
    else cout<<"No";
    return 0;
}