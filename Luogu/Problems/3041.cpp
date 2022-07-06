#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e4+10,K=1e3+10;
struct NODE {
    int cnt,next;
    int ch[3];
} tr[N];
int idx;
int dp[K][N];

int new_node() {
    assert(idx<N);
    return ++idx;
}

void add(string &s) {
    int root=0;
    for(int j=0;j<s.length();j++) {
        int c=s[j]-'A';
        if(!tr[root].ch[c]) 
            tr[root].ch[c]=new_node();
        root=tr[root].ch[c];
    }
    tr[root].cnt++;
}

void build() {
    queue<int> q;
    for(int i=0;i<3;i++) 
        if(tr[0].ch[i]) 
            q.push(tr[0].ch[i]);
    while(q.size()) {
        auto root=q.front();
        q.pop();
        for(int i=0;i<3;i++) {
            int &cur=tr[root].ch[i];
            int pre=tr[tr[root].next].ch[i];
            if(!cur) cur=pre;
            else {
                tr[cur].next=pre;
                tr[cur].cnt+=tr[pre].cnt;
                q.push(cur);
            }
        }
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        string in;
        cin>>in;
        add(in);
    }
    build();
    for(int i=0;i<=k;i++) memset(dp[i],0xcf,sizeof (int)*(idx+1));
    dp[0][0]=0;
    for(int i=0;i<k;i++) {
        for(int j=0;j<=idx;j++) {
            for(int k=0;k<3;k++) {
                int cur=tr[j].ch[k];
                dp[i+1][cur]=max(dp[i+1][cur],tr[cur].cnt+dp[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<=idx;i++) ans=max(ans,dp[k][i]);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}