#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10;
vector<pair<int,int>> adj[N];
int edge[N],poi[N];
int n;

set<int> st;
void dfs(int u,int fa,int res){
    for(auto [v,id]:adj[u]){
        if(v==fa) continue;
        if(res>=n) {
            edge[id]=*st.lower_bound(n);
            poi[v]=res^edge[id];
        }
        else {
            edge[id]=*st.lower_bound(0);
            poi[v]=n^edge[id];
        }
        st.erase(edge[id]);
        st.erase(poi[v]);
        dfs(v,u,res^edge[id]^poi[v]);
    }
}

void solve(){
    int p;
    cin>>p;
    n=1<<p;
    st.clear();
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(b,i);
        adj[b].emplace_back(a,i);
    }
    for(int i=1;i<2*n;i++) st.insert(i);
    st.erase(n);
    poi[1]=n;
    dfs(1,-1,n);

    cout<<1<<endl;
    for(int i=1;i<=n;i++) cout<<poi[i]<<" \n"[i==n];
    for(int i=1;i<n;i++) cout<<edge[i]<<" \n"[i==n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}