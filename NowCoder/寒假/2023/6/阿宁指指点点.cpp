#include <map>
#include <tuple>
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
map<string,int> id;
constexpr int N=2e4+10;
LL cnt[N],real[N],ans[N],qid;

void solve() {
    int n,T,R;
    cin>>n>>T>>R;
    // t,op,name,w,q
    vector<tuple<LL,int,int,LL,int>> event(n);
    event.reserve(n*3);
    for(int i=0;i<n;i++) {
        auto &[t,op,name,w,q]=event[i];
        string s;
        cin>>op>>t>>s;
        int idx=id.size()+1;
        if(id.count(s)==0) id[s]=idx;
        name=id[s];
        if(op==2) cin>>w,op=0;
        else op=2,q=++qid,event.emplace_back(t+R,1,name,0,0);
        
        LL recent_upd=t/T*T;
        event.emplace_back(recent_upd,1,0,0,0);
    }
    sort(event.begin(),event.end());
    debug(event);

    vector<int> upd;
    auto update=[&](int x) {
        if(x==0) {
            for(auto y:upd) cnt[y]=real[y];
            upd.clear();
        }
        else cnt[x]=real[x];
    };

    for(const auto &[t,op,name,w,q]:event) {
        debug(t,op,name,w,q);
        if(op==1) update(name);
        else if(op==0) {
            real[name]+=w;
            upd.push_back(name);
        }
        else ans[q]=cnt[name];
    }

    for(int i=1;i<=qid;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}