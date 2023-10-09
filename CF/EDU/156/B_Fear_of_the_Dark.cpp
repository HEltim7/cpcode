#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
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
    int px,py,ax,ay,bx,by;
    cin>>px>>py>>ax>>ay>>bx>>by;

    auto dis=[&](int a,int b,int c,int d) {
        int x=a-c;
        int y=b-d;
        return sqrt(x*x+y*y);
    };

    double ans=numeric_limits<double>::max();
    ans=min(ans,max(dis(ax,ay,px,py),dis(ax,ay,0,0)));
    ans=min(ans,max(dis(bx,by,px,py),dis(bx,by,0,0)));
    ans=min(ans,max({dis(ax,ay,0,0),dis(bx,by,px,py),dis(ax,ay,bx,by)/2}));
    ans=min(ans,max({dis(ax,ay,px,py),dis(bx,by,0,0),dis(ax,ay,bx,by)/2}));
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}