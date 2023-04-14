#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;

void solve() {
    int x,y,p,q;
    cin>>x>>y>>p>>q;
    LD ans=0;
    if(p<=x&&q<=y) {
        ans=LD(1)*max(p,x-p)*max(q,y-q)/(x*y);
    }
    else if(p<=x) {
        ans=LD(1)*max(p,x-p)*y/(x*y+max(p,x-p)*(q-y));
    }
    else if(q<=y) {
        ans=LD(1)*max(q,y-q)*x/(x*y+max(q,y-q)*(p-x));
    }
    else {
        ans=LD(1)*x*y/(p*q);
    }
    cout<<fixed<<setprecision(12);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}