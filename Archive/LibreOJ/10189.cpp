#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;

    vector<pair<LL,LL>> q(1);
    LL prep=0,prepx=0,res=0,ans=0;
    for(int i=1,xi,pi,ci,idx=0;i<=n;i++) {
        cin>>xi>>pi>>ci;
        prep+=pi;
        prepx+=1LL*pi*xi;

        assert(idx<q.size());
        auto [x,y]=q[idx];
        LL b=y-xi*x;
        while(idx+1<q.size()) {
            auto [x,y]=q[idx+1];
            if(y-xi*x<=b) {
                b=y-xi*x;
                idx++;
            }
            else break;
        }

        res=b+xi*prep-prepx+ci;
        x=prep;
        y=res+prepx;
        while(q.size()>=2) {
            auto [xl,yl]=q[q.size()-2];
            auto [xr,yr]=q[q.size()-1];
            if((y-yr)*(x-xl)<=(y-yl)*(x-xr)) q.pop_back();
            else break;
        }

        q.emplace_back(x,y);
        if(pi==0) ans=min(ans,res);
        else ans=res;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}