#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=310,M=2e4+10,INF=0x3f3f3f3f;
int e[M],ne[M],f[M],idx;
int h[N],q[N],arc[N],d[N];
int n,m,S,T;
typedef long long LL;
vector<LL> path;
map<LL,LL> nums,rnums;

inline void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

int dfs(int id,int lim){
    if(id==T) return lim;
    int flow=0;
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        int ver=e[i];
        arc[id]=i;
        if(d[ver]==d[id]+1&&f[i]){
            int t=dfs(ver,min(f[i],lim-flow));
            if(!t) d[ver]=-1;
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

bool bfs(){
    memset(d,-1,sizeof d);
    q[0]=S,arc[S]=h[S],d[S]=0;
    int hh=0,tt=1;
    while(hh<tt){
        int ver=q[hh++];
        for(int i=h[ver];~i;i=ne[i]){
            int t=e[i];
            if(d[t]==-1&&f[i]){
                d[t]=d[ver]+1;
                arc[t]=h[t];
                if(t==T) return 1;
                q[tt++]=t;
            }
        }
    }
    return 0;
}

int dinic(){
    int F=0,flow=0;
    while(bfs()) while(flow=dfs(S,INF)) F+=flow;
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    S=0,T=N-1;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++){
        LL in;
        cin>>in;
        add(S,i,1),add(i+n,T,1);
        nums.insert({in,i});
        rnums.insert({i,in});
    }
    for(auto [in,i]:nums){
        if(nums.find(in*2)!=nums.end())
            add(i,nums[in*2]+n,1);
        LL x=in/3;
        if(x*3==in&&nums.find(x)!=nums.end())
            add(i,nums[x]+n,1);
        add(S,i,1),add(i+n,T,1);
        nums.insert({in,i});
    }
    dinic();
    int end=0;
    for(int i=h[S];~i;i=ne[i]){
        if(f[i]){
            end=e[i];
            break;
        }
    }
    path.push_back(end);
    for(int i=1;i<n;i++){
        for(int j=h[end+n];~j;j=ne[j]){
            if(f[j]&&e[j]!=T){
                end=e[j];
                path.push_back(end);
                break;
            }
        }
    }
    reverse(path.begin(),path.end());
    for(auto x:path) cout<<rnums[x]<<' ';
    return 0;
}