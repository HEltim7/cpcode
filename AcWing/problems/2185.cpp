#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl<<flush
const int N=110,M=1e3+10,INF=0x3f3f3f3f;
int ne[M],e[M],f[M],w[M],idx;
int h[N],q[N],d[N],pre[N],mf[N];
int n,m,S,T;
bool inq[N],mark[N];
vector<int> ans;
string city[N];

inline void add(int a,int b,int c,int d){
    e[idx]=b,f[idx]=c,w[idx]=d,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,w[idx]=-d,ne[idx]=h[b],h[b]=idx++;
}

bool spfa(){
    memset(d,0x3f,sizeof d);
    memset(mf,0,sizeof mf);
    int hh=0,tt=1;
    q[0]=S,d[S]=0,mf[S]=INF;
    while(hh!=tt){
        int ver=q[hh++];
        if(hh==N) hh=0;
        inq[ver]=0;

        for(int i=h[ver];~i;i=ne[i]){
            int t=e[i];
            if(f[i]&&d[t]>d[ver]+w[i]){
                d[t]=d[ver]+w[i];
                pre[t]=i;
                mf[t]=min(mf[ver],f[i]);
                if(!inq[t]){
                    q[tt++]=t;
                    if(tt==N) tt=0;
                    inq[t]=1;
                }
            }
        }
    }
    return mf[T]>0;
}

void EK(int &flow,int &cost){
    flow=cost=0;
    while(spfa()){
        flow+=mf[T],cost+=mf[T]*d[T];
        for(int i=T;i!=S;i=e[pre[i]^1]){
            f[pre[i]]-=mf[T];
            f[pre[i]^1]+=mf[T];
        }
    }
}

void dfs(int root){
    if(root>1&&root<n) ans.push_back(root);
    for(int i=h[root];~i;i=ne[i]){
        int ver=e[i];
        if(!mark[ver]&&f[i]==0&&i%2==0){
            mark[ver]=1;
            mark[e[i^1]]=1;
            dfs(ver);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    S=0,T=N-1;
    memset(h,-1,sizeof h);
    map<string,int> id;
    for(int i=1;i<=n;i++){
        cin>>city[i],id.emplace(city[i],i);
        if(i!=n&&i!=1) add(i,i+n,1,-1);
    }
    for(int i=1;i<=m;i++){
        string a,b;
        cin>>a>>b;
        if(id[a]==1&&id[b]==n) add(id[a]+n,id[b],2,0);
        if(id[a]>id[b]) add(id[b]+n,id[a],1,0);
        else add(id[a]+n,id[b],1,0);
    }
    add(S,1+n,2,0);
    add(n,T,2,0);
    int flow,cost;
    EK(flow,cost);
    if(flow<=1){
        cout<<"No Solution!";
        return 0;
    }
    cout<<2-cost<<endl;

    vector<int> root;
    ans.push_back(1);
    for(int i=h[1+n];~i;i=ne[i]) if(f[i]==0) root.push_back(e[i]);
    dfs(root[0]);
    ans.push_back(n);
    for(auto x:ans) cout<<city[x]<<endl;

    ans.clear();
    dfs(root[1]);
    reverse(ans.begin(),ans.end());
    ans.push_back(1);
    for(auto x:ans) cout<<city[x]<<endl;
    return 0;
}