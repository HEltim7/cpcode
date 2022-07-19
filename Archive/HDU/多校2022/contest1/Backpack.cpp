#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=(1<<10)+10,H=9;
int v[N],w[N],n,m;
bool pre[N][N],suf[N][N],mark[N][N];

struct Node {
    int ch[2][2]; //ch[0]不选，ch[1]=选，-1非法
    bool val[2]; //val[x]=x是否可行
    void init() {
        val[0]=val[1]=0;
    }
} dp[N][N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

bool getbit(int x,int bit) {
    return x&(1<<bit);
}

void bfs(int bit) {
    memset(mark, 0, sizeof mark);
    queue<pair<int,int>> q;
    q.emplace(n,m);
    while(q.size()) {
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(mark[i][j]) continue;
        else mark[i][j]=1;

        auto &cur=dp[i][j];

    }
}

void cal(int bit) {
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            auto &cur=dp[i][j];
            cur.init();
            for(int k=0;k<2;k++) {
                int s=cur.ch[k][0];
                if(s!=-1&&dp[i-1][s].val[k]) cur.val[k]=1;
                s=cur.ch[k][1];
                if(s!=-1&&dp[i-1][s].val[k]^getbit(w[i], bit)) cur.val[k]=1;
            }
        }
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            auto &cur=dp[i][j];
            cur.ch[0][0]=cur.ch[1][0]=j;
            if(j-v[i]>=0) cur.ch[0][1]=cur.ch[1][1]=j-v[i];
            else cur.ch[0][1]=cur.ch[1][1]=-1;
        }
    
    //起点可达
    pre[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<2;k++) {
                int s=dp[i][j].ch[0][k];
                if(s!=-1&&pre[i-1][s]) pre[i][j]=1;
            }
    //终点可达
    suf[n][m]=1;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--) 
            if(suf[i][j])
                for(int k=0;k<2;k++) {
                    int s=dp[i][j].ch[0][k];
                    if(s!=-1) suf[i-1][s]=1;
                }
    //能从起点走到终点
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<2;k++) {
                int s=dp[i][j].ch[0][k];
                if(s!=-1&&(!pre[i-1][s]||!suf[i-1][s]))
                    dp[i][j].ch[0][s]=dp[i][j].ch[1][s]=-1;
            }

    int ans=0;
    dp[0][0].val[0]=1;
    for(int bit=H;bit>=0;bit--) {
        cal(bit);
        if(dp[n][m].val[1]) { //可以置1
            ans+=1<<bit;
            bfs(bit);
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}