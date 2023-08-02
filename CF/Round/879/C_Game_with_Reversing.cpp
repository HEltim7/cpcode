#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    string x,y,z;
    cin>>x>>y;
    z=y;
    reverse(z.begin(),z.end());

    int d1=0,d2=0;
    for(int i=0;i<x.size();i++) {
        if(x[i]!=y[i]) d1++;
        if(x[i]!=z[i]) d2++;
    }

    int ans1=d1%2==0?d1*2:(d1-1)*2+1;
    int ans2;
    if(d2==0) ans2=2;
    else ans2=d2%2==1?d2*2:(d2-1)*2+1;
    cout<<min(ans1,ans2)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}