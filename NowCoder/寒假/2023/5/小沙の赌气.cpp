#include <set>
#include <vector>
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
using PII=pair<int,int>;
constexpr int N=1e5+10,INF=int(1e9)+10;
set<PII> st[2];
int l[2][N],r[2][N];

void solve() {
    int n;
    cin>>n;
    st[0].emplace(0,0);
    st[1].emplace(0,0);
    st[0].emplace(INF,INF);
    st[1].emplace(INF,INF);
    for(int i=1;i<=n;i++) cin>>l[0][i]>>r[0][i];
    for(int i=1;i<=n;i++) cin>>l[1][i]>>r[1][i];
    for(int i=1;i<=n;i++) {
        debug(i);
        for(int j=0;j<2;j++) {
            int L=l[j][i],R=r[j][i];
            vector<PII> seg;
            auto &cur=st[j];
            auto lit=--cur.upper_bound(PII(L,INF));
            auto rit=++cur.upper_bound(PII(R,0));
            while(lit!=rit) {
                seg.push_back(*lit);
                lit=cur.erase(lit);
            }
            seg.push_back(PII(L,R));
            sort(seg.begin(),seg.end());
            debug(j,seg);

            auto [l,r]=seg.front();
            for(int i=1;i<seg.size();i++) {
                auto [ll,rr]=seg[i];
                if(r+1<ll) {
                    cur.emplace(l,r);
                    l=ll,r=rr;
                }
                else r=max(r,rr);
            }
            cur.emplace(l,r);
        }
        debug(st[0]);
        debug(st[1]);

        int sa=st[0].begin()->second;
        int ya=st[1].begin()->second;
        if(sa==ya) cout<<"win_win!"<<endl<<0<<endl;
        else if(sa>ya) cout<<"sa_win!"<<endl<<sa-ya<<endl;
        else cout<<"ya_win!"<<endl<<ya-sa<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}