#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
string digit="0123456789ABCDEF";

void solve() {
    int n;
    cin>>n;
    int a=n/16;
    n%=16;
    cout<<digit[a]<<digit[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}