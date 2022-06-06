#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<unordered_map>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int ind[N];
pair<int,int> read[N];
vector<int> adj[N];
int fa[N];
int n,m;
bool mark[N];
bool st[N];

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void bfs(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(ind[i]==1) q.push(i),mark[i]=1;
    while(q.size()){
        int h=q.front();
        q.pop();
        for(auto x:adj[h]){
            if(mark[x]) continue;
            if(--ind[x]<=1) q.push(x),mark[x]=1;
        }
    }
}

inline LL get(int x,int y){
    return 1LL*x*N+y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        if(z!=1) cout<<endl;
        unordered_map<LL,int> ump;
        cin>>n>>m;
        for(int i=1;i<=n;i++) fa[i]=i;
        memset(ind,0,sizeof (int)*(n+1));
        memset(mark,0,sizeof (bool)*(n+1));
        memset(st,0,sizeof (bool)*(n+1));
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=m;i++) cin>>read[i].first>>read[i].second;
        bool isok=0;
        for(int i=1;i<=m;i++){
            auto [a,b]=read[i];
            st[a]=st[b]=1;
            adj[a].push_back(b);
            adj[b].push_back(a);
            ump.insert({get(a,b),i});
            ump.insert({get(b,a),i});
            ind[a]++,ind[b]++;
            a=findfa(a),b=findfa(b);
            if(a==b){
                isok=1;
                break;
            }
            else fa[a]=b;
        }

        if(!isok){
            cout<<"-1";
            continue;
        }
        bfs();
        vector<int> tmp,ans;
        int start=-1,pre=-1;
        for(int i=1;i<=n;i++)
            if(!mark[i]&&st[i]){
                start=i;
                break;
            }
        for(int i=start;;){
            for(auto x:adj[i]){
                if(x==pre||mark[x]) continue;
                else{
                    pre=i,ans.push_back(ump[get(x,i)]);
                    i=x;
                    break;
                }
            }
            if(i==start) break;
        }

        sort(ans.begin(),ans.end());
        assert(ans.front()!=0);
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<(i==ans.size()-1?"":" ");
    }
    return 0;
}