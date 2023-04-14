#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<unordered_set>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10;
unordered_set<int> adj[N];
vector<pair<int,int>> path;
int n;
bool pass[N];

void dfs(int deep,int x,int end){
    if(deep==n-1){
        // assert(adj[x].find(end)!=adj[x].end());
        if(adj[x].find(end)==adj[x].end()) return ;
        
        adj[x].erase(end);
        adj[end].erase(x);
        path.emplace_back(x,end);
        return;
    }
    for(auto s:adj[x]){
        if(pass[s]||s==end) continue;
        pass[s]=1;
        path.emplace_back(x,s);
        adj[x].erase(s);
        adj[s].erase(x);
        dfs(deep+1,s,end);
        break;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        vector<pair<int,int>> res;
        cin>>n;
        for(int i=1;i<=n;i++) adj[i].clear();
        cout<<"Case #"<<z<<": ";
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j) adj[i].insert(j);
        int ans=0;
        for(int i=1,cnt=1;cnt<=n/2;i+=2,cnt++) {
            path.clear();
            memset(pass,0,sizeof (bool)*(n+1));
            pass[i+1]=1;
            dfs(1,i+1,i);
            if(path.size()<n-1) break;
            ans++;
            for(auto x:path) res.push_back(x);
        }
        cout<<ans<<endl;
        for(int i=0;i<res.size();i++)
            cout<<res[i].first<<' '<<res[i].second<<endl;
    }
    return 0;
}