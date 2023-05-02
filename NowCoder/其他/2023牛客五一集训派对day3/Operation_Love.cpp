#include <algorithm>
#include <array>
#include <cassert>
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
using LD=long double;
using P=pair<LD,LD>;
constexpr int N=20;
constexpr LD L=9*9-0.5L,S=8*8-0.5L;

void solve() {
    vector<P> p(N);
    for(auto &[x,y]:p) cin>>x>>y;
    auto len=[&](P &a,P &b) {
        LD x=a.first-b.first;
        LD y=a.second-b.second;
        return x*x+y*y;
    };
    for(int i=0;i<N;i++) {
        int j=(i+1)%N;
        if(len(p[i],p[j])>=L) {
            int l=(i-1+N)%N;
            int r=(j+1)%N;

            auto get=[&](P &s,P &t) {
                return P(t.first-s.first,t.second-s.second);
            };
            LD u1,v1,u2,v2;
            if(len(p[l],p[i])>=S) {
                tie(u1,v1)=get(p[i],p[j]);
                tie(u2,v2)=get(p[i],p[l]);
            }
            else if(len(p[j],p[r])>=S) {
                tie(u1,v1)=get(p[j],p[i]);
                tie(u2,v2)=get(p[j],p[r]);
            }
            else assert(0);

            if(u1*v2-u2*v1>=0) cout<<"left"<<endl;
            else cout<<"right"<<endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}