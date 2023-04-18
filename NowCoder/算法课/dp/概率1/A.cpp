#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;

void solve() {
    LL k,x;
    cin>>k>>x;
    cout<<fixed<<setprecision(2);
    if(x*2<=k) {
        cout<<LD(0)<<endl;
        return;
    }
    LD l=max(k-x,0LL);
    LD r=min(x,k);
    LD p=(k*(r-l)-(r*r-l*l)/2)/x;
    p/=x;
    p+=l/x;
    p=1-p;
    cout<<p<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}