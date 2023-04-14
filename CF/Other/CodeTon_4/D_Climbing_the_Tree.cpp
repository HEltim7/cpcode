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
using LL=long long;

void solve() {
    int q;
    cin>>q;
    LL L=1,R=2e18;
    for(int i=1;i<=q;i++) {
        int op;
        cin>>op;
        if(op==1) {
            LL a,b,c,n;
            cin>>a>>b>>n;
            c=a-b;

            LL l,r;
            if(n==1) {
                l=1,r=a;
            }
            else {
                auto findl=[&]() {
                    LL l=a+1,r=2e18;
                    while(l<r) {
                        LL mid=l+r>>1;
                        if((mid-a+c-1)/c>=n-1) r=mid;
                        else l=mid+1;
                    }
                    return l;
                };

                auto findr=[&]() {
                    LL l=a+1,r=2e18;
                    while(l<r) {
                        LL mid=l+r+1>>1;
                        if((mid-a+c-1)/c>n-1) r=mid-1;
                        else l=mid;
                    }
                    return l;
                };

                l=findl();
                r=findr();
            }

            if(r<L||l>R) {
                cout<<0<<' ';
            }
            else {
                cout<<1<<' ';
                L=max(L,l);
                R=min(R,r);
                debug(L,R);
            }
        }
        else {
            LL a,b,c;
            cin>>a>>b;
            c=a-b;

            auto get=[&](LL h) {
                if(a>=h) return 1LL;
                return (h-a+c-1)/c+1;
            };

            LL ln=get(L);
            LL rn=get(R);
            debug(ln,rn);

            if(ln!=rn) cout<<-1<<' ';
            else cout<<ln<<' ';
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}