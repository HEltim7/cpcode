#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
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
constexpr int N=210,M=10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    
    auto read=[&]() {
        vector<int> cnt(M);
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
            assert(arr[i]>=1&&arr[i]<=9);
            cnt[arr[i]]++;
        }
        return cnt;
    };

    auto remove=[&](vector<int> v) {
        cout<<"- "<<v.size()<<' ';
        for(int x:v) cout<<x<<' ';
        cout<<endl;
        n-=v.size();
    };

    auto fin=[&](int ans) {
        cout<<"! "<<ans<<endl;
        return;
    };

    auto find_dif=[&](vector<int> &pre,vector<int> &cur) {
        int type=0;
        for(int i=1;i<M;i++) {
            if(cur[i]>pre[i]) {
                type=i;
                break;
            }
        }
        return type;
    };

    auto find_mimic=[&](int type) {
        for(int i=1;i<=n;i++) {
            if(arr[i]==type) return i;
        }
        assert(0);
        return -1;
    };

    auto &&cnt1=read();
    remove({});
    auto &&cnt2=read();

    int type=find_dif(cnt1, cnt2);
    if(!type) {
        remove({});
        auto &&cnt=read();
        type=find_dif(cnt2, cnt);
    }

    vector<int> cnt3(M);
    for(int i=1;i<=n;i++) if(arr[i]==type) cnt3[arr[i]]++;

    vector<int> rm;
    for(int i=1;i<=n;i++) if(arr[i]!=type) rm.push_back(i);
    remove(rm);

    auto &&cnt4=read();
    type=find_dif(cnt3, cnt4);

    if(!type) {
        remove({});
        auto &&cnt=read();
        type=find_dif(cnt4, cnt);
    }

    fin(find_mimic(type));
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}