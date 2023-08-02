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

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    LL ans=0;
    auto find_right=[&](int idx) {
        vector<int> stk;
        stk.emplace_back(idx);
        auto pop=[&](int idx) {
            while(stk.size()&&arr[stk.back()]!=1) stk.pop_back();
            ans+=idx-stk.back();
            stk.pop_back();
        };
        while(idx<n) {
            int cur=arr[++idx];
            if(cur==1) stk.emplace_back(idx);
            else {
                while(stk.size()&&cur!=arr[stk.back()]+1) pop(idx);
                if(stk.empty()) break;
                else stk.emplace_back(idx);
            }
        }
        while(stk.size()) pop(n+1);
        return idx;
    };

    for(int i=1;i<=n;i++) {
        if(arr[i]!=1) continue;
        i=find_right(i);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}