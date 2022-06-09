#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<debug>
using namespace std;

#define endl '\n'
const int N=4e5+10,M=N*8,INF=0x3f3f3f3f;
int e[M],ne[M],f[M];
int h[N],d[N],arc[N],q[N];
int S=0,T=N-1,ab=T-1,ba=T-2,idx,vidx;

void add(int a,int b,int c){
    e[idx]=b,f[idx]=c,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,f[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

int dfs(int id,int lim){
    if(id==T) return lim;
    int flow=0;
    for(int i=arc[id];~i&&flow<lim;i=ne[i]){
        int ver=e[i];
        arc[id]=i;
        if(f[i]&&d[ver]==d[id]+1){
            int t=dfs(ver,min(f[i],lim-flow));
            if(!t) d[ver]=-1;
            f[i]-=t,f[i^1]+=t,flow+=t;
        }
    }
    return flow;
}

bool bfs(){
    memset(d,-1,sizeof (int)*(vidx+10));
    d[T]=d[ab]=d[ba]=-1;
    q[0]=S,arc[S]=h[S],d[S]=0;
    int hh=0,tt=1;
    while(hh<tt){
        int ver=q[hh++];
        for(int i=h[ver];~i;i=ne[i]){
            int t=e[i];
            if(f[i]&&d[t]==-1){
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

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int n=a+b+c+d;
    string s;
    cin>>s;
    int cnta=0,cntb=0;
    for(auto x:s) if(x=='A') cnta++; else cntb++;
    if(cnta!=a+c+d||cntb!=b+c+d) {
        cout<<"NO"<<endl;
        return;
    }

    memset(h,-1,sizeof (int)*(2*n+10));
    h[T]=h[ab]=h[ba]=-1;
    add(ab,T,c),add(ba,T,d);
    for(int i=1,pre=0,last=0;i<s.size();i++) {
        if(s[i-1]=='A'&&s[i]=='B'||s[i-1]=='B'&&s[i]=='A') {
            if(s[i]=='B') add(++vidx,ab,1);
            else add(++vidx,ba,1);
            if(pre) add(last,vidx,1);
            add(vidx+1,vidx,1);
            add(S,++vidx,1);
            pre=1,last=vidx;
        }
        else pre=0;
    }
    int flow=dinic();
    debug(flow);
    if(flow==c+d) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}