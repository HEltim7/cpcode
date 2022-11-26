#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,INF=0x3f3f3f3f;
bool mark[N][2][12][12];
int dp[N][2][12][12];
int a[N],b[N],n;

int dfs(int r,int p,int cnt1,int cnt2,int idx1,int idx2) {
    if(r>n) return 0;
    int &cur=dp[r][p][cnt1][cnt2];
    if(mark[r][p][cnt1][cnt2]) return cur;
    mark[r][p][cnt1][cnt2]=1;
    if(p==0) {
        if(cnt1&&idx1<=n) cur=dfs(r,1,cnt1-1,cnt2,idx1+1,idx2)+a[idx1];
        else cur=-INF;
        cur=max(cur,dfs(r,1,cnt1,cnt2,idx1,idx2+1));
    }
    else {
        if(cnt2&&idx2<=n) cur=dfs(r+1,0,cnt1,cnt2-1,idx1,idx2+1)-b[idx2];
        else cur=INF;
        cur=min(cur,dfs(r+1,0,cnt1,cnt2,idx1+1,idx2));
    }
    return cur;
}

void solve() {
    int k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(a+1,a+1+n,greater<>());
    sort(b+1,b+1+n,greater<>());
    cout<<dfs(1,0,k,k,1,1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}