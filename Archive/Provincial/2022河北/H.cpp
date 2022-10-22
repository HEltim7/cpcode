#include <cmath>
#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using LD=long double;

void solve() {
    LD val=sqrtl(2);
    LD x=1;
    int n;
    cin>>n;
    for(int i=1;i<n;i++) x*=val;
    cout<<fixed<<setprecision(2)<<x<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}