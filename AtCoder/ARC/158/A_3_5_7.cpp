#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    vector<LL> x(3);
    cin>>x[0]>>x[1]>>x[2];
    sort(x.begin(),x.end());
    LL sum=0;
    for(int i=2;i>=0;i--) x[i]-=x[0],sum+=x[i];
    if(sum%6||(x[1]-x[0])&1) {
        cout<<-1<<endl;
        return;
    }

    LL ans=0;
    int t=min({(x[2]-x[0])/4,(x[2]-x[1])/2,(x[1]-x[0])/2});
    ans+=t;
    x[0]+=4*t;
    x[1]+=2*t;
    assert(x[0]==x[1]||x[1]==x[2]);
    if(x[0]==x[1]) {
        int t=(x[2]-x[1])/6;
        ans+=t*2;
        x[0]+=6*t;
        x[1]+=6*t;
    }
    else if(x[1]==x[2]) {
        int t=(x[2]-x[0])/6;
        ans+=t*2;
        x[0]+=8*t;
        x[1]+=2*t;
        x[2]+=2*t;
    }
    if(!(x[0]==x[1]&&x[1]==x[2])) debug(x);
    assert(x[0]==x[1]&&x[1]==x[2]);
    debug(x);
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