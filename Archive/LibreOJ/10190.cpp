#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    LL A,B,C;
    cin>>n>>A>>B>>C;

    LL res=0,pre=0;
    vector<pair<LL,LL>> q(1);
    for(int i=1,in,idx=0;i<=n;i++) {
        cin>>in;
        pre+=in;
        
        assert(idx<q.size());
        auto [x,y]=q[idx];
        LL k=2*A*pre;
        LL b=y-k*x;
        while(idx+1<q.size()) {
            auto [x,y]=q[idx+1];
            if(y-k*x>=b) {
                b=y-k*x;
                idx++;
            }
            else break;
        }
        
        res=b+A*pre*pre+B*pre+C;
        x=pre;
        y=res+A*pre*pre-B*pre;

        while(q.size()>=2) {
            auto [xl,yl]=q[q.size()-2];
            auto [xr,yr]=q[q.size()-1];
            if((y-yr)*(x-xl)>=(y-yl)*(x-xr)) q.pop_back();
            else break;
        }
        q.emplace_back(x,y);
    }
    cout<<res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}