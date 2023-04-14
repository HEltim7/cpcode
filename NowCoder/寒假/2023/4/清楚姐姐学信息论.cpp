#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;

void solve() {
    int x,y;
    cin>>x>>y;
    LD rx=pow(LD(x),LD(y));
    LD ry=pow(LD(y),LD(x));
    
    if(rx==ry) cout<<min(x,y);
    else if(rx<ry) cout<<y;
    else cout<<x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}