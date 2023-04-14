#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,M=1e5+10;
int step[N];
bool trap[M],mark[M];

void solve() {
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>step[i];
    cin>>m;
    for(int i=1,in;i<=m;i++) cin>>in,trap[in]=1;

    queue<int> q;
    q.push(0);
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(mark[u]||trap[u]) continue;
        mark[u]=1;
        for(int i=1;i<=n;i++) {
            int v=u+step[i];
            if(v<M) q.push(v);
        }
    }
    int x;
    cin>>x;
    cout<<(mark[x]?"Yes":"No");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}