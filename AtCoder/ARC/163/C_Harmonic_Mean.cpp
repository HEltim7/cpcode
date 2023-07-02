#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <random>
using namespace std;
auto gen=mt19937(random_device{}());

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

int rndint(int l,int r) {
    int len=r-l+1;
    int x=gen()%len;
    return l+x;
}

constexpr int N=500;
vector<int> ans[N+10];
set<int> noans;
vector<int> hasans;
constexpr int LIM=1e9;

void dabiao() {
    ans[3]={2,3,6};
    ans[4]={2,3,9,18};
    ans[5]={3,4,5,6,20};
    ans[6]={2,3,16,18,36,48};
    ans[7]={2,3,15,21,44,60,77};
    ans[8]={3,4,5,12,20,28,30,70};
    ans[9]={2,5,9,14,21,35,63,70,90};
    ans[10]={3,4,6,15,18,24,30,32,90,96};
    ans[11]={3,4,6,16,18,21,44,45,72,77,80};
    ans[12]={3,5,8,9,15,30,35,36,40,50,63,75};
    hasans={3,4,5,6,7,8,9,10,11,12};
}

void bf(set<int,greater<>> res,vector<int> apply) {
    sort(apply.begin(),apply.end());
    for(int off=0;res.size()<N;) {
        auto it=res.begin();
        for(int i=1;i<=off;i++) {
            it=next(it);
            if(it==res.end()) return;
        }
        LL cur=*it;

        bool bad=0;
        for(int x:apply) {
            LL ne=cur*x;
            if(ne>LIM||res.find(ne)!=res.end()) {
                off++;
                bad=1;
                break;
            }
        }
        if(bad) continue;

        res.erase(it);
        for(int x:apply) res.insert(cur*x);
        int sz=res.size();
        if(ans[sz].size()) continue;
        else if(sz<=N) {
            for(int x:res) ans[sz].push_back(x);
            noans.erase(sz);
            hasans.push_back(sz);
        }
    }
}

void init() {
    for(int i=13;i<=N;i++) noans.insert(i);
    dabiao();
    auto toset=[&](int i) {
        set<int,greater<>> st;
        for(int x:ans[i]) st.insert(x);
        return st;
    };
    for(int i=3;i<=12;i++) {
        auto st=toset(i);
        for(int j=3;j<=12;j++) bf(st, ans[j]);
    }

    while(noans.size()) {
        int i=rndint(1, hasans.size());
        int j=rndint(1, hasans.size());
        i=hasans[i-1];
        j=hasans[j-1];
        debug(i,j);
        assert(ans[i].size()&&ans[j].size());
        auto st=toset(i);
        bf(st, ans[j]);
        debug(noans.size());
    }
}

void solve() {
    int n;
    cin>>n;
    if(n==1) {
        cout<<"Yes"<<endl;
        cout<<1<<endl;
        return;
    }
    if(n<=2) {
        cout<<"No"<<endl;
        return;
    }

    cout<<"Yes"<<endl;
    for(int x:ans[n]) cout<<x<<' ';
    cout<<endl;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}