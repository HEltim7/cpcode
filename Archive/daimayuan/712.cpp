#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL n,m,k;
    cin>>n>>m>>k;
    if(n<=2*k-1&&m<=2*k-1) cout<<"Alice";
    else if((n*m)&1) cout<<"Alice";
    else cout<<"Bob";
    return 0;
}