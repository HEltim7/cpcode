#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;

void solve() {
    int k,q;
    cin>>k>>q;

    auto lch=[](LL x) { return x-(lowbit(x)>>1); };
    auto rch=[](LL x) { return x+(lowbit(x)>>1); };
    auto findp=[&](LL x) {
        LL px=x+lowbit(x);
        if(lch(px)==x) return px;
        return x-lowbit(x);
    };

    LL root=1LL<<k;
    while(q--) {
        LL x,lid=1,l=0,rid=0;
        cin>>x;
        for(LL cur=root;cur!=x;) {
            if(x>cur) {
                lid+=cur-l;
                rid+=cur-l-1;
                l=cur;
                cur=rch(cur);
            }
            else {
                lid++;
                cur=lch(cur);
            }
        }
        
        debug(lid,l,rid);
        for(LL cur=x;;) {
            rid+=cur-l;
            l=cur;
            if(rch(cur)==cur||rch(cur)>root) break;
            cur=rch(cur);
        }
        cout<<lid<<' '<<x<<' '<<rid<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}