#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
using BS=bitset<N>;
int ans[N][N];
BS mark[N],cur;

void solve() {
    int n,k;
    cin>>n>>k;
    if((n&1)||k>=n) {
        cout<<"Impossible"<<endl;
        return;
    }
    for(int r=1;r<=k;r++) for(int i=1;i<=n;i++) ans[r][i]=0;
    for(int i=1;i<=n;i++) mark[i].set(),mark[i][0]=0,mark[i][i]=0;

    for(int r=1;r<=k;r++) {
        cur.reset();
        cur[0]=0;

        auto find=[&](int i) {
            int idx=mark[i]._Find_first();
            while(idx<n&&cur[idx]) idx=mark[i]._Find_next(idx);
            return idx>n?0:idx;
        };

        for(int i=1;i<=n;i++) {
            if(ans[r][i]) continue;

            int idx=find(i);
            if(!idx) {
                cout<<"Impossible"<<endl;
                return;
            }
            cur[i]=1;
            cur[idx]=1;
            mark[i][idx]=0;
            mark[idx][i]=0;
            ans[r][i]=idx;
            ans[r][idx]=i;
        }
    }

    for(int r=1;r<=k;r++) {
        for(int i=1;i<=n;i++) {
            cout<<ans[r][i]<<" \n"[i==n];
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