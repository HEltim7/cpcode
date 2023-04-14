#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef pair<int,int> PII;
const int N=3e2+10,M=3e4+10,INF=0x3f3f3f3f;
const double eps=1e-8;
int ne[M],e[M],f[M],idx;
int h[N],d[N],q[N],arc[N];
int n,S,T;
double D;
PII ice[N];

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

inline void restore(){
    for(int i=0;i<idx;i+=2){
        f[i]+=f[i^1];
        f[i^1]=0;
    }
}

inline bool check(PII a,PII b){
    int x=a.first-b.first;
    int y=a.second-b.second;
    x=x*x,y=y*y;
    return x+y-D<=eps;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    S=N-1;
    int t;
    cin>>t;
    while(t--){
        memset(h,-1,sizeof h);
        int cnt=0,total=0;
        idx=0;
        cin>>n>>D;
        D=D*D;
        for(int i=0;i<n;i++){
            int x,y,a,b;
            cin>>x>>y>>a>>b;
            total+=a;
            ice[i]={x,y};
            add(S,i,a);
            add(i,i+n,b);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(ice[i],ice[j])){
                    add(i+n,j,INF);
                    add(j+n,i,INF);
                }
            }
        }
        for(int i=0;i<n;i++){
            T=i;
            if(dinic()==total){
                cout<<i<<' ';
                cnt++;
            }
            restore();
        }
        if(cnt) cout<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}