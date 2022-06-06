#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
vector<int> adj[N];
int deg[N],ans[N];
bool pre[2][N];
PII dp[2][N];

bool get(PII a,PII b) {
    if(a.first==b.first) return a.second>b.second;
    else return a.first<b.first;
}

PII dfs(int u,int fa,bool type) {
    if(dp[type][u].second) return dp[type][u];
    int cnt=0,sum=0;
    if(type) {
        cnt=1,sum+=deg[u];
        for(auto v:adj[u]) {
            if(v==fa) continue;
            auto [c,s]=dfs(v,u,!type);
            pre[type][v]=!type;
            cnt+=c,sum+=s;
        }
    }
    else {
        sum+=1;
        for(auto v:adj[u]) {
            if(v==fa) continue;
            bool t=get(dfs(v,u,0),dfs(v,u,1));
            pre[type][v]=t;
            cnt+=dp[t][v].first;
            sum+=dp[t][v].second;
        }
    }
    dp[type][u]={cnt,sum};
    return {cnt,sum};
}

void get_ans(int u,int fa,bool type) {
    if(pre[type][u]) ans[u]=deg[u];
    else ans[u]=1;
    for(int v:adj[u]) if(v!=fa) get_ans(v,u,pre[type][u]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++,deg[b]++;
    }
    if(n==2) {
        cout<<"2 2"<<endl<<"1 1";
        return 0;
    }
    bool t=get(dfs(1,-1,0),dfs(1,-1,1));
    cout<<dp[t][1].first<<' '<<dp[t][1].second<<endl;
    if(t) ans[1]=deg[1];
    else ans[1]=1;
    for(int v:adj[1]) get_ans(v,1,t);

    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    return 0;
}