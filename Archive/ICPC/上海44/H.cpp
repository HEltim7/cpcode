#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PLI=pair<LL,int>;
const int N=1e5+10;
int arr[N];
vector<int> adj[N];

PLI dfs(int x,int fa,LL mid){
    PLI res={arr[x],0};
    vector<PLI> ch;
    for(auto s:adj[x]) if(s!=fa) ch.push_back(dfs(s,x,mid));
    sort(ch.begin(),ch.end());
    for(auto [a,b]:ch) 
        if(res.first+a<=mid) res.first+=a,res.second+=b;
        else res.second+=b+1;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        LL l=0,r=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            l=max(l,1LL*arr[i]);
            r+=arr[i];
        }
        while(l<r){
            LL mid=l+r>>1;
            if(dfs(1,-1,mid).second<=k-1) r=mid;
            else l=mid+1;
        }
        cout<<"Case #"<<z<<": "<<l<<endl;
    }
    return 0;
}