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

struct DisjointUnionSet {
    vector<int> fa,sz;
    vector<pair<int&,int>> fah,szh;

    void init(int n) {
        fah.clear();
        szh.clear();
        fa.resize(n+1);
        sz.assign(n+1,1);
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        while(x!=fa[x]) x=fa[x];
        return x;
    }

    bool same(int x,int y) {
        return find(x)==find(y);
    }

    bool join(int x,int y) {
        x=find(x);
        y=find(y);
        if(x==y) {
            fah.emplace_back(fa[0],fa[0]);
            szh.emplace_back(sz[0],sz[0]);
            return false;
        }
        if(sz[x]<sz[y]) swap(x,y);
        fah.emplace_back(fa[y],fa[y]);
        szh.emplace_back(sz[x],sz[x]);
        sz[x]+=sz[y];
        fa[y]=x;

        

        return true;
    }

    void undo() {
        assert(!fah.empty());
        fah.back().first=fah.back().second;
        szh.back().first=szh.back().second;
        fah.pop_back(),szh.pop_back();
    }

    int size(int x) {
        return sz[find(x)];
    }

    DisjointUnionSet() = default;
    DisjointUnionSet(int n) { init(n); }
} dsu;

namespace sd {
    #define lch (u<<1)
    #define rch (u<<1|1)
    vector<pair<int,int>> seg[N];
    int k[N],ans[N];
    int rng_l,rng_r;

    void add(int u,int x,int y,int l,int r,pair<int,int> val) {
        if(x>r||y<l) return;
        if(x<=l&&y>=r) seg[u].emplace_back(val);
        else {
            int mid=(l+r)/2;
            add(lch,x,y,l,mid,val);
            add(rch,x,y,mid+1,r,val);
        }
    }
    void add(int x,int y,pair<int,int> val) {
        add(1,x,y,rng_l,rng_r,val);
    }

    void dfs(int u,int l,int r) {
        for(auto [x,y]:seg[u]) {
            x=dsu.find(x);
            y=dsu.find(y);

        }

        if(l==r) ;
        else {
            int mid=(l+r)/2;
            dfs(lch,l,mid);
            dfs(rch,mid+1,r);
        }

    }
    void solve() {
        dfs(1,rng_l,rng_r);
    }

    #undef lch
    #undef rch
}

void solve() {
    int n;
    io>>n;
    sd::rng_l=1,sd::rng_r=n-1;
    vector<int> arr(n);
    for(int &x:arr) io>>x;
    auto num=arr;

    for(int i=1;i<n;i++) {
        int u,v,k;
        io>>u>>v>>k;
        sd::k[i]=k;
        sd::add(1, i-1, {u,v});
        sd::add(i+1, n-1, {u,v});
        num.push_back(k);
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=0;i<n;i++) 
        arr[i]=lower_bound(num.begin(),num.end(),arr[i])-num.begin()+1;
    for(int i=1;i<n;i++)
        sd::k[i]=lower_bound(num.begin(),num.end(),sd::k[i])-num.begin()+1;
    
    sgt.rng_l=1,sgt.rng_r=num.size();
    for(int i=0;i<n;i++) {
        sgt.build(root[i+1], arr[i]);
    }

    dsu.init(n);
    sd::solve();
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