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
    int n,k;
    cin>>n>>k;
    vector<int> arr(n),pos,neg;
    int ans=0;
    for(auto &x:arr) {
        cin>>x;
        if(x>=0) pos.push_back(x);
        else neg.push_back(x);
    }

    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end(),greater<>());
    while(k--) {
        debug(pos,neg);
        if(pos.size()<=1&&neg.size()<=1) ans+=pos.back()*neg.back();
        else if(pos.size()<=1) {
            ans+=neg.back()*(*++neg.rbegin());
            neg.pop_back();
            neg.pop_back();
        }
        else if(neg.size()<=1) {
            ans+=pos.back()*(*++pos.rbegin());
            pos.pop_back();
            pos.pop_back();
        }
        else {
            LL a=pos.back()*(*++pos.rbegin());
            LL b=neg.back()*(*++neg.rbegin());
            debug(a,b);
            ans+=max(a,b);
            if(a>=b) {
                pos.pop_back();
                pos.pop_back();
            }
            else {
                neg.pop_back();
                neg.pop_back();
            }
        }
        debug(ans);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}