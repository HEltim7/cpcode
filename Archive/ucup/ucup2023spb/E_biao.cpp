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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
vector<string> valid;
constexpr int N=960+10,M=10;
vector<int> mp[N][M];

void solve() {
    string s="KQRRBBNN";
    sort(s.begin(),s.end());
    do {
        int r1=find(s.begin(),s.end(),'R')-s.begin();
        int r2=find(s.begin()+r1+1,s.end(),'R')-s.begin();
        int k=find(s.begin(),s.end(),'K')-s.begin();
        int b1=find(s.begin(),s.end(),'B')-s.begin();
        int b2=find(s.begin()+b1+1,s.end(),'B')-s.begin();
        if(r1<k&&k<r2&&(b1&1)!=(b2&1)) valid.emplace_back(s),cout<<s<<endl;
    }while (next_permutation(s.begin(),s.end()));

    auto match=[&](string &x,string &y) {
        int res=0;
        for(int i=0;i<8;i++) if(x[i]==y[i]) res++;
        return res;
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}