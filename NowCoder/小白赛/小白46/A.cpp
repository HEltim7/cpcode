#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    if(n&1) cout<<n/2<<' '<<n/2+1<<endl;
    else cout<<n/2;
    return 0;
}