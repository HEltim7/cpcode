#include <deque>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    deque<pair<LL,LL>> q(1);
    int n,l;
    cin>>n>>l;

    LL s=0,L=l+1,res;
    for(int i=1,idx=0,c;i<=n;i++) {
        cin>>c;
        s+=c+1;
        assert(idx<q.size());
        auto [x,y]=q[idx];
        LL k=2*(s-L);
        LL b=y-k*x;
        
        while(idx+1<q.size()) {
            auto [x,y]=q[idx+1];
            if(y-k*x<=b) {
                b=y-k*x;
                idx++;
            }
            else break;
        }
        res=b+(s-L)*(s-L);
        x=s,y=res+s*s;

        while(q.size()>=2) {
            auto [xl,yl]=q[q.size()-2];
            auto [xr,yr]=q[q.size()-1];
            if((y-yr)*(x-xl)<=(y-yl)*(x-xr)) q.pop_back();
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