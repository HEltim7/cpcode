#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10,H=30;
int val[N];
vector<pair<int,int>> adj[N];

struct NODE {
    int ch[2];
} tr[32*N];
int idx;

int getxor(int x,int val,int bit){
    if(bit<0) return 0;
    int s=(val>>bit)&1;
    if(tr[x].ch[s^1]) s^=1;
    return (s<<bit)+getxor(tr[x].ch[s],val,bit-1); 
}

void build(int x,int val,int bit){
    if(bit<0) return;
    else{
        int s=(val>>bit)&1;
        if(!tr[x].ch[s]) tr[x].ch[s]=++idx;
        build(tr[x].ch[s],val,bit-1);
    }
}

void dfs(int x,int fa,int v){
    val[x]=v;
    build(0,v,H);
    for(auto [s,d]:adj[x])
        if(s!=fa) dfs(s,x,v^d);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    dfs(1,-1,0);
    
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,val[i]^getxor(0,val[i],H));
    cout<<ans;
    return 0;
}