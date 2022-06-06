#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
using PII=pair<int,int>;
const int N=1e5+10,M=30;

int p[N],n;
int fa[N][M+1],dis[N][M+1],dep[N];
vector<TIII> edges;
vector<PII> adj[N];

void dfs(int x,int p){
    for(auto [s,d]:adj[x]){
        if(s==p) continue;
        dep[s]=dep[x]+1;
        fa[s][0]=x;
        dis[s][0]=d;
        for(int i=1;i<=M;i++)
            fa[s][i]=fa[fa[s][i-1]][i-1];
        for(int i=1;i<=M;i++)
            dis[s][i]=max(dis[fa[s][i-1]][i-1],dis[s][i-1]);
        dfs(s,x);
    }
}

int lca(int a,int b){
    int res=0;
    if(dep[a]<dep[b]) swap(a,b);
    for(int k=M;~k;k--)
        if(dep[fa[a][k]]>=dep[b])
            res=max(res,dis[a][k]),a=fa[a][k];
    if(a==b) return res;
    for(int k=M;~k;k--)
        if(fa[a][k]!=fa[b][k])
            res=max({res,dis[a][k],dis[b][k]}),a=fa[a][k],b=fa[b][k];
    return max({res,dis[a][0],dis[b][0]});
}

int findfa(int x){
    if(p[x]==x) return x;
    return p[x]=findfa(p[x]);
}

void kruskal(){
    sort(edges.begin(),edges.end());
    int cnt=0;
    for(auto [d,u,v]:edges){
        u=findfa(u),v=findfa(v);
        if(u!=v){
            p[u]=v;
            adj[u].emplace_back(v,d);
            adj[v].emplace_back(u,d);
            if(++cnt>=n-1) break;
        }
    }
}

namespace io {
    const int MAXBUF = 1e6, MAXLEN = 1e6;
    char buf[MAXBUF], *pl, *pr;
    char str[MAXLEN];

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T>
    inline T rd(T &x) {
        x = 0;
        T f = 1;
        char c = gc();
        while (!isdigit(c)) {
            if (c == '-') f = -1;
            c = gc();
        }
        while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
        if (c != '.') return x = x * f;
        for (double t = 0.1; c = gc(), isdigit(c); t *= 0.1) x += (c - '0') * t;
        return x = x * f;
    }

    inline char* rd(char *p = str){
        char c = gc(), *h = p;
        while (!isgraph(c)) c = gc();
        while (isgraph(c)) *p++ = c, c = gc();
        *p = '\0';
        return h;
    }

    inline char rd(char &c) {
        c = gc();
        while(!isgraph(c)) c = gc();
        return c;
    }

    inline string rd(string &s) { return s = rd(str); }

    #define read(x) io::rd(x)

    const int MAXPBUF = 1e6;
    char pbuf[MAXPBUF], *pp = pbuf;

    inline void push(const char &c) {
        if (pp - pbuf == MAXPBUF) fwrite(pbuf, 1, pp-pbuf, stdout), pp = pbuf;
        *pp++ = c;
    }

    template<typename T>
    inline void wt(T x) {
        if (x < 0) push('-'), x = -x;
        static int sta[40];
        int top = 0;
        do {
            sta[top++] = x % 10;
        } while (x/=10);
        while (top) push(sta[--top] + '0');
    }

    inline void wt(double x,int precision = 7) {
        if (x < 0) push('-'), x = -x;
        long long pre = (long long)x;
        wt(pre);
        x -= pre;
        if (precision) push('.');
        while (precision--) {
            x *= 10;
            int t = (int)x;
            x -= t;
            push(t + '0');
        }
    }

    inline void wt(const char &c) { push(c); }
    inline void wt(string &s) { for (auto &x:s) push(x); }
    inline void wt(char *p) { while (*p != '\0') push(*p++); }
    inline void wt(const char *p) { while (*p != '\0') push(*p++); }

    struct Exit {
        ~Exit() { fwrite(pbuf, 1, pp-pbuf, stdout); }
    } static exit;

    #define write(...) io::wt(__VA_ARGS__)
}

int main() {
    int m,q;
    read(n),read(m);
    for(int i=1;i<=m;i++){
        int x,y,d;
        edges.emplace_back(read(d),read(x),read(y));
    }
    for(int i=1;i<=n;i++) p[i]=i;
    kruskal();
    dep[1]=1;
    dfs(1,-1);

    read(q);
    while(q--){
        int x,y;
        read(x),read(y);
        write(lca(x,y));
        write('\n');
    }
    return 0;
}