#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=1e5+10,M=20;
LL H;
int n,full;
int tim[M],len[M];
int pre[M][N];
int sttime[1<<M];
vector<int> st[M];
LL dp[1<<M];

int cntbit(int x) {
    int res=0;
    while(x) x-=lowbit(x),res++;
    return res;
}

int caltime(int x) {
    int res=0;
    for(int i=0;i<n;i++) {
        if(x&(1<<i)) res+=tim[i];
    }
    return res;
}

bool check(int mid) {
    memset(dp, 0, sizeof(LL)*(1<<n));
    for(int i=0;i<n;i++) {
        for(auto x:st[i]) {
            int cur=mid-sttime[x];
            if(cur<=0) continue;
            for(int j=0;j<n;j++) {
                if(!(x&(1<<j))) {
                    dp[x+(1<<j)]=max(dp[x+(1<<j)],dp[x]+pre[j][min(cur,len[j])]);
                    if(dp[x+(1<<j)]>=H) return 1;
                }
            }
        }
    }
    return 0;
}

void solve() {
    cin>>n>>H;
    LL sum=0;
    for(int i=0;i<n;i++) {
        cin>>tim[i]>>len[i];
        for(int j=1;j<=len[i];j++) {
            cin>>pre[i][j];
            pre[i][j]+=pre[i][j-1];
        }
        sum+=pre[i][len[i]];
    }
    if(sum<H) {
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<(1<<n);i++) st[cntbit(i)].push_back(i);
    for(int i=0;i<(1<<n);i++) sttime[i]=caltime(i);
    full=(1<<n)-1;
    
    int l=1,r=2e6;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}