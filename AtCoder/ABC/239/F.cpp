#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=2e5+10;
typedef pair<int,int> PII;
typedef vector<int> VI;
int deg[N],degbak[N],fa[N];
VI st[N];
vector<PII> ans;
VI adj[N];
bool mark[N],FLAG=1;

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void dfs(int x,int p){
    mark[x]=1;
    int cnt=0;
    for(auto s:adj[x]){
        if(!mark[s]) dfs(s,x);
        cnt++;
    }
    if(cnt!=degbak[x]) FLAG=0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>deg[i];
        degbak[i]=deg[i];
        sum+=deg[i];
        fa[i]=i;
    }
    if(sum!=(n-1)*2){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        deg[a]--,deg[b]--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        a=findfa(a),b=findfa(b);
        if(a==b){
            cout<<-1;
            return 0;
        }
        fa[a]=b;
    }

    for(int i=1;i<=n;i++){
        fa[i]=findfa(i);
        for(int j=1;j<=deg[i];j++)
            st[fa[i]].push_back(i);
    }
    priority_queue<PII> heap;
    for(int i=1;i<=n;i++)
        if(st[i].size()) heap.push({st[i].size(),i});
    while(heap.size()>1){
        auto [asz,a]=heap.top();
        heap.pop();
        auto [bsz,b]=heap.top();
        heap.pop();
        ans.push_back({st[a].back(),st[b].back()});
        adj[st[a].back()].push_back(st[b].back());
        adj[st[b].back()].push_back(st[a].back());
        st[a].pop_back(),st[b].pop_back();

        if(st[a].size()<st[b].size()) swap(a,b);
        while(st[b].size()) st[a].push_back(st[b].back()),st[b].pop_back();
        b=findfa(b),a=findfa(a);
        fa[b]=a;
        if(st[a].size()) heap.push({st[a].size(),a});
    }
    
    dfs(1,0);
    bool res=1;
    for(int i=1;i<=n;i++) if(!mark[i]) res=0;
    if(res==0||FLAG==0){
        cout<<-1;
        return 0;
    }

    for(auto [a,b]:ans) cout<<a<<' '<<b<<endl;
    return 0;
}