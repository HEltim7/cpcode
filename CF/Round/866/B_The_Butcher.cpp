#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
using PII=pair<LL,LL>;
constexpr int N=2e5+10;
multiset<PII,greater<>> st[2];

void solve() {
    int n;
    cin>>n;
    st[0].clear();
    st[1].clear();
    
    LL sum=0;
    for(int i=1;i<=n;i++) {
        LL a,b;
        cin>>a>>b;
        st[0].emplace(a,b);
        st[1].emplace(b,a);
        sum+=1LL*a*b;
    }

    auto work=[&](int idx) {
        auto cur=st[idx];
        auto rev=st[idx^1];

        LL h,w;
        tie(h,w)=*cur.begin();
        cur.erase(cur.begin());
        rev.erase(rev.find({w,h}));
        if(sum%h) return false;
        w=sum/h-w;
        debug(idx,h,w);

        for(;cur.size();) {
            debug(cur,rev);
            if(cur.begin()->first==h) {
                auto [x,y]=*cur.begin();
                cur.erase(cur.begin());
                rev.erase(rev.find({y,x}));
                w-=y;
            }
            else if(rev.begin()->first==w) {
                auto [y,x]=*rev.begin();
                rev.erase(rev.begin());
                cur.erase(cur.find({x,y}));
                h-=x;
            }
            else return false;
        }
        return true;
    };

    vector<PII> ans;
    if(work(0)) {
        LL h=st[0].begin()->first;
        LL w=sum/h;
        ans.emplace_back(h,w);
    }
    if(work(1)) {
        LL w=st[1].begin()->first;
        LL h=sum/w;
        ans.emplace_back(h,w);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());

    cout<<ans.size()<<endl;
    for(auto [h,w]:ans) cout<<h<<' '<<w<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}