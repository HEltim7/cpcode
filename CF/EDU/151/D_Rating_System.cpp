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
constexpr int N=3e5+10;
LL arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    vector<pair<LL,LL>> vec;
    vec.emplace_back(0,0);
    LL pre=0;

    for(int i=1;i<=n;i++) {
        pre+=arr[i];
        auto work=[&]() {
            auto [k,v]=vec.back();
            vec.pop_back();
            while(vec.size()) {
                auto [kk,vv]=vec.back();
                vv=max(kk,vv+pre);
                if(max(k,v+pre)>=vv) {
                    vec.pop_back();
                }
                else break;
            }
            vec.emplace_back(k,max(v,k-pre));
        };

        work();
        if(pre>vec.back().first) {
            vec.emplace_back(pre,0);
            work();
        }
    }

    cout<<vec.front().first<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}