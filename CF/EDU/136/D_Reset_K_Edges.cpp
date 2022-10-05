#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int p[N],dep[N],ind[N],bak[N],mx[N];

int bfs(int n,int len) {
    int res=0;
    memcpy(bak, ind, sizeof(int)*(n+1));
    memset(mx, 0, sizeof(int)*(n+1));
    queue<int> q;
    for(int i=1;i<=n;i++) if(!bak[i]) q.push(i);
    while(q.size()) {
        int u=q.front();
        if(mx[u]==len-1&&p[p[u]]) res++,mx[u]=-1;
        mx[p[u]]=max(mx[p[u]],mx[u]+1);
        if(--bak[p[u]]==0) q.push(p[u]);
        q.pop();
    }
    return res;
}

void solve() {
    int n,k;
    cin>>n>>k;
    memset(ind, 0, sizeof(int)*(n+1));
    for(int i=2;i<=n;i++) {
        cin>>p[i];
        ind[p[i]]++;
    }
    
    int l=1,r=n;
    while(l<r) {
        int mid=l+r>>1;
        if(bfs(n,mid)<=k) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}