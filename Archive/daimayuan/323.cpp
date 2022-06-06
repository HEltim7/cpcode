#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
int num[N],ind[N];
vector<int> adj[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    sort(num+1,num+1+n);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(num[j]%num[i]==0) 
                ind[j]++,adj[i].push_back(j);
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++) if(ind[i]==0) q.push({i,1});
    int ans=1;
    while(q.size()){
        auto [t,step]=q.front();
        q.pop();
        for(auto x:adj[t]){
            ind[x]--;
            if(ind[x]==0) q.push({x,step+1});
        }
        ans=max(ans,step);
    }
    cout<<ans;
    return 0;
}