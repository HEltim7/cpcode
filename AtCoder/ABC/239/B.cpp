#include<iostream>
#include<cmath>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL x;
    cin>>x;
    if(x>=0) cout<<x/10;
    else cout<<(x-9)/10;
    return 0;
}