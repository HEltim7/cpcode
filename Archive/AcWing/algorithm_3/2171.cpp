#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define debug(x) cout << "[debug] " #x << " = " << x << endl
#define endl '\n'
const int N=1e3+10,M=2e4+10;
const int INF=0x3f3f3f3f;

int n,m,S,T;
int h[N],e[M],ne[M],c[M],idx;
int d[N],pre[N];//d表示从S走到某点的流的最小值
bool st[N];

//如果加边要写成++idx的形式的话，idx初值应该=1，不然找反向边会出错。
void add(int a,int b,int f){
    e[idx]=b,c[idx]=f,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,c[idx]=0,ne[idx]=h[b],h[b]=idx++;
}

bool bfs(){
    queue<int> q;
    memset(st,false,sizeof st);
    q.push(S),st[S]=1,d[S]=INF;
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=h[t];~i;i=ne[i]){
            int ver=e[i];
            if(!st[ver]&&c[i]){
                st[ver]=1;
                d[ver]=min(d[t],c[i]);
                pre[ver]=i;
                if(ver==T) return 1;
                q.push(ver);
            }
        }
    }
    return 0;
}

int EK(){
    int F=0;//最大流
    while(bfs()){
        F+=d[T];//加上T的流量
        for(int i=T;i!=S;i=e[pre[i]^1])
            c[pre[i]]-=d[T],c[pre[i]^1]+=d[T];
    }
    return F;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(h,-1,sizeof h);
    cin>>n>>m>>S>>T;
    while(m--){
        int a,b,f;
        cin>>a>>b>>f;
        add(a,b,f);
    }
    cout<<EK();
    return 0;
}