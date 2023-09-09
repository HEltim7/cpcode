#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

using LL=long long;
vector<string> valid;
constexpr int N=960+10,M=10;
vector<int> mp[N][M];

int match(string &x,string &y) {
    int res=0;
    for(int i=0;i<8;i++) if(x[i]==y[i]) res++;
    return res;
}

void init() {
    string s="KQRRBBNN";
    sort(s.begin(),s.end());
    do {
        int r1=find(s.begin(),s.end(),'R')-s.begin();
        int r2=find(s.begin()+r1+1,s.end(),'R')-s.begin();
        int k=find(s.begin(),s.end(),'K')-s.begin();
        int b1=find(s.begin(),s.end(),'B')-s.begin();
        int b2=find(s.begin()+b1+1,s.end(),'B')-s.begin();
        if(r1<k&&k<r2&&(b1&1)!=(b2&1)) valid.emplace_back(s);
    }while (next_permutation(s.begin(),s.end()));

    for(int i=0;i<valid.size();i++) {
        for(int j=0;j<valid.size();j++) {
            mp[i][match(valid[i],valid[j])].emplace_back(j);
        }
    }
}

void solve(int ans) {
#ifdef ONLINE_JUDGE
    auto ask=[&](int id) {
        cout<<valid[id]<<endl;
        int in;
        cin>>in;
        return in;
    };
#else
    auto ask=[&](int id) {
        cout<<valid[id]<<endl;
        return match(valid[ans], valid[id]);
    };
#endif
    auto inter=[&](vector<int> &a,vector<int> &b) {
        vector<int> mark(N);
        for(int x:a) mark[x]++;
        for(int x:b) mark[x]++;
        vector<int> res;
        for(int i=0;i<N;i++) if(mark[i]==2) res.emplace_back(i);
        return res;
    };

    bool patch=false;
    auto shrink=[&](vector<int> &v) {
        int maxx=numeric_limits<int>::max(),id=0;
        for(int i:v) {
            vector<int> res(M);
            for(int j:v) {
                int sam=match(valid[i], valid[j]);
                res[sam]++;
            }
            int cur=*max_element(res.begin(),res.end());
            if(patch) {
                if(cur<maxx) id=i,maxx=cur;
            }
            else if(cur<=maxx) id=i,maxx=cur;
        }
        if(id==831) patch=true;
        int cur=ask(id);
        v=inter(v, mp[id][cur]);
        return cur;
    };

    vector<int> res(960);
    iota(res.begin(), res.end(), 0);
    for(int i=1;i<=6;i++) if(shrink(res)==8) return;
    debug(res);
    debug(ans,valid[ans]);
    assert(0);
}

int main() {
    init();
    ios::sync_with_stdio(false);
#ifdef ONLINE_JUDGE
    string s;
    while(cin>>s) {
        if(s=="END") break;
        cin>>s;
        solve(0);
    }
#else
    for(int i=0;i<960;i++) solve(i);
    // solve(427);
    // debug();
    // solve(731);
    // debug();
    // solve(903);
    // solve(51);
#endif
    return 0;
}