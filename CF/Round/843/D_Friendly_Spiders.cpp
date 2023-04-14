#include <queue>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10,INF=1e9;
int arr[N],pos[N];
vector<int> adj[N],fac[N];

constexpr int M=N;
int prime[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

vector<int> get_factor(int val) {
    vector<int> res;
    while(val>1) {
        int t=minp[val];
        res.push_back(t);
        while(minp[val]==t) val/=t;
    }
    return res;
}

int dis[N],pre[N];

bool mark[N];
int bfs(int s,int t) {
    dis[s]=1;
    queue<int> q;
    q.push(s);

    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:fac[u]) {
            if(mark[v]) continue;
            mark[v]=1;
            for(int x:adj[v]) {
                if(dis[x]>dis[u]+1) {
                    dis[x]=dis[u]+1;
                    pre[x]=u;
                    if(x==t) return dis[t];
                    q.push(x);
                }
            }
        }
    }
    return dis[t];
}


void solve() {
    get_prime();
    int n,s,t;
    cin>>n;
    
    for(int i=1;i<N;i++) fac[i]=get_factor(i);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(pos[arr[i]]==0) for(auto x:fac[arr[i]]) adj[x].push_back(arr[i]);
        pos[arr[i]]=i;
    }

    for(int i=1;i<N;i++) dis[i]=INF;
    cin>>s>>t;

    if(s==t) cout<<1<<endl<<s;
    else if(arr[s]==1||arr[t]==1) cout<<-1;
    else if(arr[s]==arr[t]) cout<<2<<endl<<s<<' '<<t;
    else {
        int ans=bfs(arr[s], arr[t]);
        if(ans==INF) cout<<-1<<endl;
        else {
            cout<<ans<<endl;
            vector<int> res(1,t);
            t=arr[t];

            while(t!=arr[s]) res.push_back(pos[t=pre[t]]);
            res.pop_back();
            res.push_back(s);
            reverse(res.begin(),res.end());
            for(auto x:res) cout<<x<<' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}