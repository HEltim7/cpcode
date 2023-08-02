#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
vector<pair<int,int>> adj[N];
int kk[N],ans[N];

namespace fast_io {
    constexpr int MAXBUF = 1 << 20, MAXLEN = 1 << 20;
    char buf[MAXBUF], *pl, *pr;
    char str[MAXLEN];

    #define gc() \
    (pl == pr && (pr = (pl = buf) + fread(buf, 1, MAXBUF, stdin), pl == pr) \
    ? EOF : *pl++)

    template<typename T> T rd(T &x) {
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

    char* rd(char *p = str) {
        char c = gc(), *h = p;
        while (!isgraph(c)) c = gc();
        while (isgraph(c)) *p++ = c, c = gc();
        *p = '\0';
        return h;
    }

    char rd(char &c) {
        c = gc();
        while (!isgraph(c)) c = gc();
        return c;
    }

    string rd(string &s) { return s = rd(str); }

    template<typename... T> auto read(T&... x) { return (rd(x),...); }
    #undef gc

    constexpr int MAXPBUF = 1 << 20, PRECISION = 7;
    char pbuf[MAXPBUF], *pp = pbuf;

    void clear_buffer() { fwrite(pbuf, 1, pp-pbuf, stdout), pp = pbuf; }

    void push(const char &c) {
        if (pp - pbuf == MAXPBUF) clear_buffer();
        *pp++ = c;
    }

    template<typename T> void wt(T x) {
        if (x < 0) push('-'), x = -x;
        static int sta[40];
        int top = 0;
        do {
            sta[top++] = x % 10;
        } while (x/=10);
        while (top) push(sta[--top] + '0');
    }

    template<typename T> void wt_f(T x,int p) {
        if (x < 0) push('-'), x = -x;
        long long pre = (long long)x;
        wt(pre);
        x -= pre;
        if (p) push('.');
        while (p--) {
            x *= 10;
            int t = (int)x;
            x -= t;
            push(t + '0');
        }
    }

    void wt(const char &c) { push(c); }
    void wt(const string &s) { for (auto &x:s) push(x); }
    void wt(const char *p) { while (*p != '\0') push(*p++); }

    void wt(const float &x, int p = PRECISION) { wt_f(x,p); }
    void wt(const double &x, int p = PRECISION) { wt_f(x,p); }
    void wt(const long double &x, int p = PRECISION) { wt_f(x,p); }

    template<typename... T> void write(const T&... x) { (wt(x),...); }
    template<typename T> void writef(const T &x,const int &p) { wt_f(x,p); }

    struct IO {
        template<typename T> friend IO& 
        operator>>(IO &io, T& x) { rd(x); return io; }

        template<typename T> friend IO&
        operator<<(IO &io, const T& x) { wt(x); return io; }

        ~IO() { clear_buffer(); }
    } static io;

} using fast_io::read,fast_io::write,fast_io::writef,fast_io::io;

int root[N];
struct MergeSplitSegmentTree {
    #define lch (tr[u].ch[0])
    #define rch (tr[u].ch[1])
    constexpr static int MAX_SIZE=1e7+10;
    int rng_l,rng_r;
    
    struct Node {
        int ch[2];
        int cnt;
    } tr[MAX_SIZE];
    int idx;
 
    int new_node() {
        assert(idx<MAX_SIZE);
        return ++idx;
    }

    void pushup(int u) {
        if(lch&&rch) tr[u].cnt=max(tr[lch].cnt,tr[rch].cnt);
        else if(lch) tr[u].cnt=tr[lch].cnt;
        else if(rch) tr[u].cnt=tr[rch].cnt;
    }
    
    void merge(int &u,int v) {
        if(!u&&!v) return;
        if(!u||!v) u=u|v;
        else {
            merge(lch,tr[v].ch[0]);
            merge(rch,tr[v].ch[1]);
            pushup(u);
        }
    }

    int query(int u,int l,int r,int k) {
        if(l>=k) return tr[u].cnt;
        else {
            int mid=(l+r)/2;
            int res=0;
            if(k>mid&&rch) res=max(res,query(rch,mid+1,r,k));
            if(k<=mid&&lch) res=max(res,query(lch,l,mid,k));
            return res;
        }
    }
    int query(int u,int k) {
        return query(u,rng_l,rng_r,k);
    }

    int kth(int u,int l,int r,int k) {
        if(tr[u].cnt<k) return -1;
        if(l==r) return l;
        int mid=l+r>>1;
        if(tr[lch].cnt>=k) return kth(lch, l, mid, k);
        return kth(rch, mid+1, r, k-tr[lch].cnt);
    }

    void build(int &u,int l,int r,int p) {
        u=new_node();
        if(l==r) tr[u].cnt=1;
        else {
            int mid=l+r>>1;
            if(p<=mid) build(lch,l,mid,p);
            else build(rch,mid+1,r,p);
            pushup(u);
        }
    }
    void build(int &u,int p) {
        build(u,rng_l,rng_r,p);
    }

    #undef lch
    #undef rch
} sgt;

void dfs1(int u,int fa) {
    for(auto [v,id]:adj[u]) {
        if(v!=fa) {
            dfs1(v,u);
            sgt.merge(u, v);
            ans[id]=max(ans[id],sgt.query(root[v],kk[id]));
        }
    }
}

void dfs2(int u,int fa) {

}

void solve() {
    int n;
    io>>n;
    vector<int> arr(n);
    for(int &x:arr) io>>x;
    auto num=arr;

    for(int i=1;i<n;i++) {
        int u,v;
        io>>u>>v>>kk[i];
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
        num.push_back(kk[i]);
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=0;i<n;i++) 
        arr[i]=lower_bound(num.begin(),num.end(),arr[i])-num.begin()+1;
    for(int i=1;i<n;i++)
        kk[i]=lower_bound(num.begin(),num.end(),kk[i])-num.begin()+1;
    
    sgt.rng_l=1,sgt.rng_r=num.size();
    for(int i=0;i<n;i++) {
        sgt.build(root[i+1], arr[i]);
    }

    dfs1(1, 0);
    for(int i=1;i<n;i++) cout<<ans[i]<<endl;
}

int main() {
    int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    int t;
    io>>t;
    while(t--) solve();
    exit(0);
    return 0;
}