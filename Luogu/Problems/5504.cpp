#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e5+10,M=1e4+10;
vector<pair<LL,LL>> que[M];
int idxx[M],cntt[M];

void push(vector<pair<LL,LL>> &q,LL x,LL y) {
    while(q.size()>=2) {
        auto [xl,yl]=q[q.size()-2];
        auto [xr,yr]=q[q.size()-1];
        if((y-yr)*(x-xl)>=(y-yl)*(x-xr)) q.pop_back();
        else break;
    }
    q.emplace_back(x, y);
}

void solve() {
    int n;
    cin>>n;
    LL res=0;
    for(int i=1,s;i<=n;i++) {
        cin>>s;
        auto &q=que[s];
        auto &idx=idxx[s];
        auto &cnt=++cntt[s];
        push(q, cnt-1, res+1LL*s*(cnt-1)*(cnt-1));
        if(idx+1>=q.size()-1) idx=q.size()-1;
        
        auto [x,y]=q[idx];
        LL k=2LL*cnt*s;
        LL b=y-k*x;
        while(idx-1>=0) {
            auto [x,y]=q[idx-1];
            if(y-k*x>=b) {
                b=y-k*x;
                idx--;
            }
            else break;
        }
        
        res=b+1LL*cnt*cnt*s;
    }
    cout<<res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}