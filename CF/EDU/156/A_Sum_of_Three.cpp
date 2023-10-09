#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n<6) {
        cout<<"NO"<<endl;
        return;
    }
    int x=1,y=2,z=n-3;
    if(z%3==0||z<=y) {
        y=4;
        z=n-5;
    }
    if(z%3==0||z<=y) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        cout<<x<<' '<<y<<' '<<z<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}