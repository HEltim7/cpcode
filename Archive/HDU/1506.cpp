#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

template<typename T=int> struct CartesianTree {
    vector<int> lch,rch,stk;
    vector<T> val;
    int root,idx;

    void extend(int x) {
        idx++;
        lch.emplace_back(0);
        rch.emplace_back(0);
        val.emplace_back(x);
        
        while(stk.size()&&val[stk.back()]>x) {
            lch[idx]=stk.back();
            stk.pop_back();
        }
        if(stk.size()) rch[stk.back()]=idx;
        else root=idx;
        stk.emplace_back(idx);
    }

    void clear() {
        root=idx=0;
        lch.assign(1,{});
        rch.assign(1,{});
        val.assign(1,{});
        stk.clear();
    }

    CartesianTree(int sz=0) {
        lch.reserve(sz+1);
        rch.reserve(sz+1);
        val.reserve(sz+1);
        stk.reserve(sz+1);
        clear();
    }
};

void solve(int n) {
    CartesianTree<> tr(n);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        tr.extend(in);
    }

    LL ans=0;
    function<int(int)> dfs=[&](int u) {
        if(!u) return 0;
        int sz=1;
        sz+=dfs(tr.lch[u]);
        sz+=dfs(tr.rch[u]);
        ans=max(ans,1LL*tr.val[u]*sz);
        return sz;
    };
    dfs(tr.root);

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n&&n) solve(n);
    return 0;
}