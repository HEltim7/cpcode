#include <set>
#include <map>
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
constexpr int N=1e5+10;
int ans[N];

namespace dsu {
    int id[N],ed[N],ori[N],sz[N],hch[N],idx;
    vector<pair<int,int>> adj[N];
    int w[N],eid[N];
    set<int> tot_st,cur_st;
    map<int,int> tot_mp,cur_mp;
    int tot_res,cur_res;

    void insert(int val,set<int> &st,map<int,int> &mp,int &maxx) {
        auto mit=mp.find(val);
        if(mit==mp.end()) {
            auto sit=st.find(val);
            if(sit==st.end()) {
                st.insert(val);
            }
            else {
                st.erase(sit);
                mp.emplace(val,2);
                maxx=max(maxx,val);
            }
        }
        else mit->second++;
    }

    void erase(int val,set<int> &st,map<int,int> &mp,int &maxx) {
        auto mit=mp.find(val);
        if(mit==mp.end()) {
            auto sit=st.find(val);
            if(sit!=st.end()) st.erase(sit);
        }
        else {
            mit->second--;
            if(mit->second==1) {
                mp.erase(mit);
                st.insert(val);
                maxx=mp.rbegin()->first;
            }
        }
    }

    void init(int u,int fa) {
        sz[u]=1;
        id[u]=++idx;
        ori[id[u]]=u;
        insert(w[u], tot_st, tot_mp, tot_res);
        for(auto [v,i]:adj[u]) {
            if(v!=fa) {
                eid[v]=i;
                init(v,u);
                if(sz[v]>sz[hch[u]]) hch[u]=v;
                sz[u]+=sz[v];
            }
        }
        ed[u]=idx;
    }

    void solve(int u,int fa,bool keep) {
        auto add=[](int id) {
            int x=ori[id];
            insert(w[x], cur_st, cur_mp, cur_res);
            erase(w[x], tot_st, tot_mp, tot_res);
        };

        auto del=[](int id) {
            int x=ori[id];
            erase(w[x], cur_st, cur_mp, cur_res);
            insert(w[x], tot_st, tot_mp, tot_res);
        };
        
        for(auto [v,_]:adj[u]) if(v!=fa&&v!=hch[u]) solve(v,u,0);
        if(hch[u]) solve(hch[u],u,1);
        for(auto [v,_]:adj[u])
            if(v!=fa&&v!=hch[u]) 
                for(int i=id[v];i<=ed[v];i++) add(i);
        add(id[u]);
        
        ans[eid[u]]=max(tot_res,cur_res);

        if(!keep) for(int i=id[u];i<=ed[u];i++) del(i);
    }

    void clear(int n=N-1) {
        idx=0;
        fill(hch,hch+n+1,0);
        for(int i=0;i<=n;i++) adj[i].clear();
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        dsu::adj[u].push_back({v,i});
        dsu::adj[v].push_back({u,i});
    }
    vector<int> num(1,0);
    for(int i=1;i<=n;i++) cin>>dsu::w[i],num.push_back(dsu::w[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        dsu::w[i]=lower_bound(num.begin(),num.end(),dsu::w[i])-num.begin();
    
    dsu::cur_mp.emplace(0,2);
    dsu::tot_mp.emplace(0,2);
    dsu::init(1, -1);
    dsu::solve(1, 0, 1);
    for(int i=1;i<n;i++) cout<<num[ans[i]]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}