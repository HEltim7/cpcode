#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e3+10;
vector<pair<LL,LL>> q[N];
int idxx[N];

void solve() {
    int n,m;
    LL pre=0,res=0;
    q[0].resize(1);
    cin>>n>>m;
    for(int i=1,in;i<=n;i++) {
        cin>>in;
        pre+=in;
        for(int j=min(i,m);j>=1;j--) {
            int &idx=idxx[j];
            auto &last=q[j-1];
            auto &cur=q[j];

            assert(idx<last.size());
            auto [x,y]=last[idx];
            LL k=pre*2;
            LL b=y-k*x;
            while(idx+1<last.size()) {
                auto [x,y]=last[idx+1];
                if(y-k*x<=b) {
                    b=y-k*x;
                    idx++;
                }
                else break;
            }

            res=b+pre*pre;
            if(i==n&&j==m) {
                cout<<res*m-pre*pre;
                return;
            }
            
            x=pre;
            y=res+pre*pre;
            while(cur.size()>=2) {
                auto [xl,yl]=cur[cur.size()-2];
                auto [xr,yr]=cur[cur.size()-1];
                if((y-yr)*(x-xl)<=(y-yl)*(x-xr)) cur.pop_back();
                else break;
            }
            cur.emplace_back(x,y);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}