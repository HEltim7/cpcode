#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;
#define endl '\n'

void solve() {
    int n,k;
    cin>>n>>k;
    cout<<(n-1+k-2)/(k-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}