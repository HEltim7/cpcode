#include <algorithm>
#include <array>
#include <cassert>
#include <cstdlib>
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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=300*4+10;
int color[N][N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=4*n;i++)
        for(int j=1;j<=4*n;j++)
            cin>>color[i][j];
    
    vector<pair<int,int>> ans;
    vector<int> cnt(N);
    auto put=[&](int r,int c,int x,int y,int p,int q) {
        for(int i=r+p;i<=x;i+=2) {
            for(int j=c+q;j<=y;j+=2) {
                ans.emplace_back(i,j);
                cnt[color[i][j]]++;
            }
        }
    };

    auto work=[&](bool x) {
        int mid=n*2;
        ans.clear();
        cnt.assign(cnt.size(),0);
        put(1, 1, mid, mid, 1^x, 0^x);
        put(1, mid+1, mid, n*4, 0^x, 0^x);
        put(mid+1, mid+1, n*4, n*4, 0^x, 1^x);
        put(mid+1, 1, n*4, mid, 1^x, 1^x);
        if(*max_element(cnt.begin(),cnt.end())>n) return;
        cout<<"YES"<<endl;
        for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
        exit(0);
    };

    work(0);
    work(1);
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}