#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e4+10;
int w[N],cw[N],y[N],z[N];
bool mark[N];

void solve() {
    int n,th;
    cin>>n>>th;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x>>y[x]>>z[x]>>w[x];
    }

    queue<int> q;
    for(int i=2;i<=n+1;i++) {
        if(w[i]) {
            int cur=w[i];
            q.emplace(i);
            mark[i]=1;
            while(q.size()) {
                int u=q.front();
                q.pop();
                cw[u]+=cur;
                if(!mark[y[u]]) q.push(y[u]),mark[y[u]]=1;
                if(!mark[z[u]]) q.push(z[u]),mark[z[u]]=1;
            }
            memset(mark, 0, sizeof (bool)*(i+1));
        }
    }

    int cnt=0;
    for(int i=2;i<=n+1;i++) if(cw[i]>=th) cout<<i<<' '<<cw[i]<<endl,cnt++;
    cout<<cnt<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}