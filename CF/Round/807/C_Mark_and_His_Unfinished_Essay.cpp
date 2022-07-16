#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<LL,LL>;
const int N=2e5+10;
char arr[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

void solve() {
    int n,c,q;
    cin>>n>>c>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<PII> seg(1,{1,n});
    vector<LL> len(1,n);
    for(int i=1;i<=c;i++) {
        LL l,r;
        cin>>l>>r;
        seg.emplace_back(l,r);
        len.push_back(r-l+1+len.back());
    }
    while(q--) {
        LL k;
        cin>>k;
        int pos=lower_bound(len.begin(),len.end(),k)-len.begin();
        while(pos>0) {
            LL pre=len[pos-1];
            LL l=seg[pos].first;
            k=k-pre+l-1;
            pos=lower_bound(len.begin(),len.end(),k)-len.begin();
        }
        cout<<arr[k]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}