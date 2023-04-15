#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10,offset=2.5e3;

bool grid[N][N];
int maxx;

void set(int r,int c) {
    maxx=max(maxx,abs(r));
    maxx=max(maxx,abs(c));
    r+=offset;
    c+=offset;
    assert(r>=0&&r<N&&c>=0&&c<N);
    grid[r][c]=1;
}

void draw(int r,int c,int x,int y) {
    int addr,addc;
    if(r==x) addr=0;
    else if(r<x) addr=1;
    else if(r>x) addr=-1;

    if(c==y) addc=0;
    else if(c<y) addc=1;
    else if(c>y) addc=-1;

    set(r,c),set(x,y);
    while(r!=x||c!=y) {
        r+=addr;
        c+=addc;
        set(r,c);
    }
}

vector<pair<int,int>> trans(int r,int c) {
    vector<pair<int,int>> res;
    res.emplace_back(r,c);
    res.emplace_back(c,-r);
    res.emplace_back(-c,r);
    res.emplace_back(-r,-c);
    return res;
}

void solve() {
    int n;
    cin>>n;

    auto work=[&](int r,int c,int x,int y) {
        auto vs=trans(r,c);
        auto vt=trans(x,y);

        for(int j=0;j<vs.size();j++) {
            auto [r1,c1]=vs[j];
            auto [r2,c2]=vt[j];
            draw(r1,c1,r2,c2);
        }
    };

    for(int i=1,edge=4;i<=n;i+=2,edge*=4) {
        int r=0;
        int c=edge;
        int x=edge/2;
        int y=edge/2;
        work(r, c, x, y);
    }
    
    for(int i=2,edge=8;i<=n;i+=2,edge*=4) {
        int c=0;
        int r=edge;
        int y=edge/2;
        int x=edge/2;
        work(r, c, x, y);
    }

    draw(0, maxx, 0, -maxx);
    draw(-maxx, 0, maxx, 0);
    draw(-(maxx/2), -(maxx/2), maxx/2, maxx/2);
    draw(-(maxx/2), maxx/2, maxx/2, -(maxx/2));

    // for(int r=-maxx;r<=maxx;r++) {
    //     int x=r+offset;
    //     debug(grid[x],-maxx+offset,maxx+offset);
    // }

    for(int r=-maxx;r<=maxx;r++) {
        for(int c=-maxx;c<=maxx;c++) {
            int x=r+offset;
            int y=c+offset;
            cout<<(grid[x][y]?'*':' ');
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}