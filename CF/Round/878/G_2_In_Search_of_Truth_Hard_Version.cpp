#include <algorithm>
#include <array>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
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

#define endl '\n'
using LL=long long;

constexpr int M=1e6;
auto gen=mt19937(random_device()());
int arr[M+10],idx=1;

void solve() {
    int pos;
    cin>>pos;
    auto ask=[&](int x) {
        if(x>=0) cout<<"+ ";
        else cout<<"- ";
        cout<<abs(x)<<endl;
#ifdef ONLINE_JUDGE
        int in;
        cin>>in;
        return in;
#else
        idx=(idx+x-1)%M+1;
        return arr[idx];
#endif
    };

    auto fin=[&](int x) {
        cout<<"! "<<x<<endl;
        exit(0);
    };

    auto rndint=[&](int l,int r) {
        int len=r-l+1;
        int x=gen()%len;
        return x+l;
    };

    int maxx=pos;
    for(int i=1;i<=200;i++) {
        maxx=max(maxx,pos=ask(rndint(1, M)));
    }

    map<int,int> mp;
    mp[pos]=400;
    for(int i=1;i<=400;i++) {
        int p=ask(1);
        if(mp.find(p)!=mp.end()) fin(i);
        mp[p]=400-i;
        pos=p;
    }

    for(int i=0;i<400;i++) {
        int mv=maxx+i*400;
        int p=ask(mv);
        if(mp.find(p)!=mp.end()) {
            int x=mp[p];
            fin(maxx+i*400+x);
        }
        else ask(-mv);
    }

    assert(0);
}

int main() {
#ifndef ONLINE_JUDGE
    for(int i=1;i<=M;i++) arr[i]=i;
    shuffle(arr+1, arr+1+M, gen);
#endif
    ios::sync_with_stdio(0);
    solve();
    return 0;
}