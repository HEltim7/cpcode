#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;

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
}; using Mint=Modint<int,long long,int(1e9)+7>;

template<int size,typename T=int> struct SparseTable {
    constexpr static int M=__lg(size);
    T arr[size],st[M][size];

    void build(int n) {
        for(int i=1;i<=n;i++) st[0][i]=arr[i];
        for(int k=1,t=1<<k;k<M;k++,t<<=1)
            for(int i=1,j=i+t-1,mid=i+t/2;j<=n;i++,j++,mid++)
                st[k][i]=max(st[k-1][i],st[k-1][mid]);
    }

    T query(int l,int r) {
        if(r<l) return 0;
        int k=__lg(r-l+1);
        return max(st[k][l],st[k][r-(1<<k)+1]);
    }
};

SparseTable<N> st;
vector<int> pos[N];
vector<Mint> res[N];
int arr[N],p[N],ind[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++) pos[i].clear();
    for(int i=1;i<=n;i++) {
        ind[i]=p[i]=0;
        cin>>arr[i];
        st.arr[i]=arr[i];
        pos[arr[i]].push_back(i);
        res[i].clear();
        res[i].resize(m+1);
    }

    st.build(n);
    vector<pair<int,int>> stk{make_pair(arr[1], 1)};
    for(int i=2;i<=n;i++) {
        while(stk.size()&&stk.back().first<arr[i]) stk.pop_back();
        if(stk.size()) p[i]=stk.back().second;
        stk.emplace_back(arr[i],i);
        if(p[i]<i-1) {
            int minn=st.query(p[i]+1, i-1);
            int idx=*lower_bound(pos[minn].begin(),pos[minn].end(),p[i]+1);
            p[idx]=i;
        }
    }

    int root=0;
    queue<int> q;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) res[i][j]=1;
    for(int i=1;i<=n;i++) if(!p[i]) root=i; else ind[p[i]]++;
    for(int i=1;i<=n;i++) if(!ind[i]) q.push(i);
    vector<Mint> pre(m+1);
    while(q.size()) {
        int u=q.front();
        q.pop();
        if(u==root) break;
        for(int i=1;i<=m;i++) pre[i]=pre[i-1]+res[u][i];
        for(int i=1;i<=m;i++) res[p[u]][i]*=pre[i-(p[u]>u)];
        if(!--ind[p[u]]) q.push(p[u]);
    }

    Mint ans;
    for(int i=1;i<=m;i++) ans+=res[root][i];
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}