# E. Paimon Segment Tree

> [CF Gym](https://codeforces.com/gym/103470/problem/E)

首先先解决时间的问题，发现问题允许离线，于是很自然的可以想到对于$[x,y]$时间段的询问，可以将其拆成$[0,y]-[0,x-1]$前缀和相减的形式，通过时间差分我们不必再维护历史版本，只需要每次计算后回答当前时间的询问即可。

现在问题转化为如何高效维护历史区间和，在线段树上维护4个信息：

- $x_1$ 表示区间长
- $x_2$ 表示区间和
- $x_3$ 表示区间平方和
- $x_4$ 表示历史区间平方和

设当前修改值为$k$，通过展开完全平方公式，得到转移方式：

- $x_1=x_1$
- $x_2=x_2+kx_1$
- $x_3=x_3+2kx_2+k^2x_1$
- $x_4=x_4+x_3+2kx_2+k^2x_1$

~~接下来最麻烦的地方就是懒标记的维护了。~~ 正当我烦恼于如何维护懒标记时，chenjb的话醍醐灌顶般的启发了我：

> 将维护的信息写成矩阵形式，就不用再考虑懒标记冲突的问题，矩阵天生的结合率使它不会发生冲突，线性代数已经帮我们解决了这个问题。

设维护的信息向量为$[x_1,x_2,x_3,x_4]$，将上述转移写成矩阵乘法形式：

$$
\begin{bmatrix}
    x_1 & x_2 & x_3 & x_4
\end{bmatrix}
\times
\begin{bmatrix}
    1 & k & k^2 & k^2 \\
    & 1 & 2k & 2k \\
    & & 1 & 1 \\
    & & & 1
\end{bmatrix}
$$

每个线段树节点维护一个信息向量，和一个$4 \times 4$的懒标记转移矩阵，转移过程变得非常清晰简单，只需要套用矩阵乘法问题就迎刃而解，tql orz.

不过这样写常数比较大，可以利用上三角矩阵这个优化常数。

PS:最后我直接裸矩阵卡常过（1965ms），一个有用的小优化是，线段树节点额外维护一个标记，用来指示懒标记是否为单位矩阵（空），在`pushdown`时就可以免去一些费时的矩阵乘法操作。

时间复杂度$\mathcal{O}(q \log n)$。

## 实现

长度感人，赛时实现这道题难度相当大。

```cpp
#include <array>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e4+10;

template<typename I,typename L,I mod> struct Modint {
    I v;
    I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    I inv() const { return pow(mod-2); }

    Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend Modint operator/(Modint l,const Modint &r) { return l/=r; }

    Modint operator++(int) { auto res=*this; *this+=1; return res; }
    Modint operator--(int) { auto res=*this; *this-=1; return res; }
    Modint operator-  () { return *this*-1; }
    Modint &operator++() { return *this+=1; }
    Modint &operator--() { return *this-=1; }

    bool operator< (const Modint &x) const { return v< x.v; }
    bool operator> (const Modint &x) const { return v> x.v; }
    bool operator<=(const Modint &x) const { return v<=x.v; }
    bool operator>=(const Modint &x) const { return v>=x.v; }
    bool operator==(const Modint &x) const { return v==x.v; }
    bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
}; using Mint=Modint<int,long long,int(1e9+7)>;

template<typename T,int R,int C=R> struct Matrix {
    array<array<T,C>,R> v;

    template<int Rr,int Cr> Matrix<T,R,Cr> operator*(const Matrix<T,Rr,Cr> &r) {
        static_assert(C==Rr,"");
        array<array<T,Cr>,R> ans;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                T res{};
                for(int k=0;k<C;k++)
                    res+=v[i][k]*r[k][j];
                ans[i][j]=res;
            }
        }
        return ans;
    }

    Matrix operator+(const Matrix &r) {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ans[i][j]=v[i][j]+r[i][j];
        return ans;
    }

    Matrix operator-(const Matrix &r) {
        array<array<T,C>,R> ans;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) ans[i][j]=v[i][j]-r[i][j];
        return ans;
    }

    Matrix &operator*=(const Matrix<T,C,C> &r) { return *this=*this*r; }
    Matrix &operator+=(const Matrix &r) { return *this=*this+r; }
    Matrix &operator-=(const Matrix &r) { return *this=*this-r; }

    Matrix pow(long long k) {
        Matrix res(1),x=*this;
        while(k) { if(k&1) res*=x; k>>=1; x*=x; }
        return res;
    }

    auto &operator[](int idx) { return v[idx]; }
    auto &operator[](int idx) const { return v[idx]; }

    void clear() { v={}; }
    void unit(T x=1) { static_assert(R==C,""); clear(); for(int i=0;i<R;i++) v[i][i]=x; }

    Matrix() { clear(); }
    Matrix(T x) { unit(x); }
    Matrix(const array<array<T,C>,R> &x) { v=x; }
}; using Mtrx=Matrix<Mint, 4>;

Mint arr[N],ans[N];

struct SegmentTree {
    #define lch (u<<1)
    #define rch (u<<1|1)
    constexpr static int MAXSIZE=N;

    struct Node {
        int l,r;
        Matrix<Mint, 4> v;
        Mtrx laz=Mtrx(1);
        bool flag;
    } tr[MAXSIZE<<2];

    void pushup(int u) {
        tr[u].v=tr[lch].v+tr[rch].v;
    }

    void pushdn(int u) {
        if(!tr[u].flag) return;
        tr[lch].v*=tr[u].laz;
        tr[rch].v*=tr[u].laz;
        tr[lch].laz*=tr[u].laz;
        tr[rch].laz*=tr[u].laz;
        tr[lch].flag=1;
        tr[rch].flag=1;
        tr[u].laz.unit();
        tr[u].flag=0;
    }

    void modify(int u,int l,int r,const Mtrx &val) {
        if(tr[u].l>=l&&tr[u].r<=r) {
            tr[u].v*=val;
            tr[u].laz*=val;
            tr[u].flag=1;
        }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            if(mid>=l) modify(lch, l, r, val);
            if(mid<r) modify(rch, l, r, val);
            pushup(u);
        }
    }

    Mint query(int u,int l,int r) {
        if(tr[u].l>=l&&tr[u].r<=r) { return tr[u].v[0][3]; }
        else {
            pushdn(u);
            int mid=tr[u].l+tr[u].r>>1;
            Mint res;
            if(mid>=l) res+=query(lch, l, r);
            if(mid<r) res+=query(rch, l, r);
            return res;
        }
    }

    void build(int u,int l,int r) {
        tr[u]={l,r};
        if(l==r) {
            tr[u].v={{{r-l+1,arr[l],arr[l]*arr[l],arr[l]*arr[l]}}};
        }
        else {
            int mid=l+r>>1;
            build(lch, l, mid);
            build(rch, mid+1, r);
            pushup(u);
        }
    }

    #undef lch
    #undef rch
} sgt;

void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<tuple<int,int,int>> mod;
    vector<tuple<int,int,int,int,int>> que;
    mod.reserve(m),que.reserve(q);
    for(int i=0;i<m;i++) {
        int l,r,x;
        cin>>l>>r>>x;
        mod.emplace_back(l,r,x);
    }
    for(int i=0;i<q;i++) {
        int l,r,x,y;
        cin>>l>>r>>x>>y;
        if(x-1>=0) que.emplace_back(x-1,l,r,i,-1);
        que.emplace_back(y,l,r,i,1);
    }

    auto get_mat=[](Mint k) {
        return Mtrx({{
            {1,k,k*k,k*k},
            {0,1,2*k,2*k},
            {0,0,1,1},
            {0,0,0,1}
        }});
    };

    sgt.build(1, 1, n);
    sort(que.begin(),que.end());
    for(int i=0,j=0;j<que.size();i++) {
        while(j<que.size()&&get<0>(que[j])==i) {
            auto [t,l,r,id,sign]=que[j++];
            ans[id]+=sign*sgt.query(1, l, r);
        }
        if(i==m) break;
        auto [l,r,x]=mod[i];
        sgt.modify(1,l,r,get_mat(x));
        if(l>1) sgt.modify(1, 1, l-1, get_mat(0));
        if(r<n) sgt.modify(1, r+1, n, get_mat(0));
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
```