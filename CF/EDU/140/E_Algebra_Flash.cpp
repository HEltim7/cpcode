#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
constexpr int N=3e5+10,M=50;
int color[N],cost[N],m;
bool edge[M][M];
unordered_map<LL,int> ump;

int dfs(LL state) {
    if(!state) return 0;
    if(ump.count(state)) return ump[state];
    int x=__lg(lowbit(state));
    LL s=state-(1LL<<x);
    LL t=s;
    for(int i=x+1;i<m;i++) if((1LL<<i&t)&&edge[x][i]) t-=1LL<<i;
    return ump[state]=max(dfs(s),edge[x][x]?0:dfs(t)+cost[x]);
}

void solve() {
    int n,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>color[i],color[i]--;
    for(int i=0;i<m;i++) cin>>cost[i],sum+=cost[i];
    for(int i=1;i<n;i++) 
        edge[color[i]][color[i+1]]=edge[color[i+1]][color[i]]=1;
    LL state=(1LL<<m)-1;
    state-=1LL<<color[1];
    if(color[n]!=color[1]) state-=1LL<<color[n];
    cout<<sum-dfs(state);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}