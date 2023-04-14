#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int dp[N],pre[N];

void solve() {
    int n;
    cin>>n;
    vector<int> res;
    vector<pair<int,int>> item(1);
    for(int i=2;;i++) {
        int cur=i*(i-1)/2;
        if(cur>n) break;
        for(int j=1,t=n;t>0;j*=2) {
            item.emplace_back(i,j);
            t-=cur*j;
        }
    }

    memset(dp+1, 0x3f, sizeof(int)*n);
    for(int i=1;i<item.size();i++) {
        auto [val,cnt]=item[i];
        int cur=val*(val-1)/2;
        int tot=cur*cnt;
        for(int k=n;k>=tot;k--) {
            if(dp[k-tot]+val*cnt<dp[k]) {
                dp[k]=dp[k-tot]+val*cnt;
                pre[k]=i;
            }
        }
    }
    
    int t=n;
    while(t) {
        auto [val,cnt]=item[pre[t]];
        t-=val*(val-1)/2*cnt;
        while(cnt--) res.push_back(val);
    }
    
    LL cnt=0;
    for(int i=0,sum=0;i<res.size();i++) {
        cnt+=1LL*sum*res[i];
        sum+=res[i];
    }
    cout<<dp[n]<<' '<<cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}