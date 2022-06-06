#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=3e5+10;
vector<int> arr[N];
vector<PII> adj[N];
vector<bool> mark[N],bak[N];
int cnt[N];

void dfs(int u) {
    while(adj[u].size()) {
        auto [v,idx]=adj[u].back();
        bool flag=mark[u].back();
        adj[u].pop_back();
        mark[u].pop_back();
        if(flag) continue;
        mark[v][idx]=bak[v][idx]=1;
        dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int m;
    cin>>m;
    vector<int> num;
    for(int i=1;i<=m;i++) {
        int n;
        cin>>n;
        for(int j=1;j<=n;j++) {
            int in;
            cin>>in;
            num.push_back(in);
            arr[i].push_back(in);
        }
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=m;i++) 
        for(auto &x:arr[i]) {
            x=lower_bound(num.begin(),num.end(),x)-num.begin()+1;
            cnt[x]++;
            adj[i].emplace_back(x+m,adj[x+m].size());
            mark[i].push_back(0);
            adj[x+m].emplace_back(i,adj[i].size()-1);
            mark[x+m].push_back(0);
        }
    for(int i=1;i<=m+num.size();i++) bak[i]=mark[i];

    for(int i=1;i<=num.size();i++) 
        if(cnt[i]&1) {
            cout<<"NO";
            return 0;
        }
    cout<<"YES"<<endl;
    
    for(int i=1;i<=m;i++) 
        if(adj[i].size()) dfs(i);
    for(int i=1;i<=m;i++) {
        for(auto x:bak[i]) 
            cout<<(x?'L':'R');
        cout<<endl;
    }
    return 0;
}