#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e6+10;

void solve() {
    int n;
    cin>>n;
    cout<<fixed<<setprecision(7)<<LD(n)/2+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}