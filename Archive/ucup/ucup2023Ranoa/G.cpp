#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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
// constexpr int N=10; 
constexpr int N=2e3+10;
bitset<N> bs[N];

void solve() {
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char in;
            cin>>in;
            bs[j][i]=in=='1';
        }
    }

    for(int j=0;j<m;j++) {
        array<bool,2> one={},zero={};
        int ne=(j+1)%n;
        for(int i=0;i<n;i++) {
            if(bs[ne][i]) one[bs[j][i]]|=1;
            else zero[bs[j][i]]|=1;
        }
        if(one[0]&&zero[0]||one[1]&&zero[1]) {
            debug(j);
            cout<<-1;
            return;
        }
    }

    vector<tuple<int,int,int>> ans;
    ans.reserve(m*m*3);
    for(int i=0;i<m;i++) {
        for(int j=i;j<m;j++) {
            int tot=0;
            auto push=[&](int id) {
                if(i!=j||id==1||id==4) ans.emplace_back(i,j,id);
                tot++;
            };

            auto cur=bs[i]^bs[j];
            int x=cur.count();
            if(x) {
                int y=(bs[i]&cur).count();
                debug(i,j,x,y);
                // 不存在 i=0,j=1 即限制 i=1,j=0(id=2) 合法
                if(x==y) push(2);
                // 不存在 i=1,j=0 即限制 i=0,j=1(id=3) 合法
                else if(y==0) push(3);
            }
            else {
                push(2);
                push(3);
            }

            cur.flip();
            x=cur.count()-(N-n);
            if(x) {
                int y=(bs[i]&cur).count();
                debug(i,j,x,y);
                // 不存在 i=0,j=0 即限制 i=1,j=1(id=4) 合法
                if(x==y) push(4);
                // 不存在 i=1,j=1 即限制 i=0,j=0(id=1) 合法
                else if(y==0) push(1);
            }
            else {
                push(1);
                push(4);
            }

            if(tot==4) {
                while(tot--) ans.pop_back();
            }
        }
    }

    assert(ans.size()<=2*m*m);
    cout<<ans.size()<<endl;
    for(auto [i,j,id]:ans) cout<<i<<' '<<j<<' '<<id<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}