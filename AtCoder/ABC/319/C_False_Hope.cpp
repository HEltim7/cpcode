#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iomanip>
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
int g[5][5],t[5][5];

void solve() {
    vector<pair<int,int>> vec;
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) vec.emplace_back(i,j);
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) cin>>g[i][j];

    auto check=[&](int a,int b,int c,int d,int e,int f) {
        vector<pair<int,int>> cur {
            {t[a][b],g[a][b]},
            {t[c][d],g[c][d]},
            {t[e][f],g[e][f]}
        };
        sort(cur.begin(),cur.end());
        return cur[0].second==cur[1].second&&cur[1].second!=cur[2].second;
    };

    int ans=0,tot=0;
    do {
        for(int i=1;i<=9;i++) {
            auto [x,y]=vec[i-1];
            t[x][y]=i;
        }
        bool valid=false;
        for(int i=1;i<=3;i++) {
            valid|=check(i,1,i,2,i,3);
            valid|=check(i,3,i,2,i,1);
            valid|=check(1,i,2,i,3,i);
            valid|=check(3,i,2,i,1,i);
        }
        valid|=check(1,1,2,2,3,3);
        valid|=check(3,3,2,2,1,1);
        valid|=check(1,3,2,2,3,1);
        valid|=check(3,1,2,2,1,3);
        ans+=!valid;
        tot++;
    } while (next_permutation(vec.begin(),vec.end()));

    cout<<fixed<<setprecision(30);
    cout<<double(ans)/tot<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}