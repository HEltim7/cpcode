#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1e3+10;
vector<int> adj[N];
int ind[N];
int n;
bool mark[N];

void remove(){
    queue<int> q;
    for(int i=1;i<=n;i++) 
        if(ind[i]==1) q.push(i);
    while(q.size()){
        int x=q.front();
        q.pop();
        ind[x]=0;
        for(auto t:adj[x]){
            if(ind[t]>0){
                ind[t]--;
                if(ind[t]==1) 
                    q.push(t);
            }
        }
    }
}

void dfs(int root,int fa){
    mark[root]=1;
    for(auto x:adj[root]){
        if(x==fa||mark[x]) continue;
        dfs(x,root);
    }
}

bool check(){
    bool res=0;
    for(int i=1;i<=n;i++) if(ind[i]) res=1;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ind[a]++,ind[b]++;
    }
    dfs(1,0);
    for(int i=1;i<=n;i++){
        if(mark[i]==0){
            cout<<"NO";
            return 0;
        }
    }
    remove();
    if(!check()){
        cout<<"NO";
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(ind[i]){
            ind[i]=1;
            break;
        }
    }
    remove();
    if(check()) cout<<"NO";
    else cout<<"YES";
    return 0;
}