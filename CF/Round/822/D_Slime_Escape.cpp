#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
constexpr LL INF=2e18,LIM=1e18;
LL arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    arr[0]=arr[n+1]=INF;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<pair<LL,LL>> stk[2];
    LL sum=0,lim=0;
    for(int i=k+1;i<=n+1;i++) {
        sum+=arr[i];
        lim=min(lim,sum);
        if(sum>=0) {
            stk[1].push_back({lim,sum});
            sum=lim=0;
        }
    }
    sum=lim=0;
    for(int i=k-1;i>=0;i--) {
        sum+=arr[i];
        lim=min(lim,sum);
        if(sum>=0) {
            stk[0].push_back({lim,sum});
            sum=lim=0;
        }
    }

    LL cur=arr[k];
    reverse(stk[0].begin(),stk[0].end());
    reverse(stk[1].begin(),stk[1].end());
    while(cur<LIM) {
        bool flag=0;
        for(int i=0;i<2;i++) {
            auto [lim,sum]=stk[i].back();
            if(lim+cur>=0) cur+=sum,stk[i].pop_back(),flag=1;
        }
        if(!flag) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}