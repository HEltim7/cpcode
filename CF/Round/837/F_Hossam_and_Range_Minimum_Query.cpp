#include <array>
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

    bool operator< (const Modint&x) { return v< x.v; }
    bool operator> (const Modint&x) { return v> x.v; }
    bool operator<=(const Modint&x) { return v<=x.v; }
    bool operator>=(const Modint&x) { return v>=x.v; }
    bool operator==(const Modint&x) { return v==x.v; }
    bool operator!=(const Modint&x) { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<LL,__int128,LL(1e18+3)>;

int root[N],arr[N];
Mint pw[N*32];

struct PersistentBitwiseTrie {
    #define lch tr[u].ch[0]
    #define rch tr[u].ch[1]

    struct Node {
        int sz;
        int ch[2];
        Mint hs;
    } tr[N*32];
    int idx;

    void hash(int u,bool dir) {
        int x,y;
        if(dir) x=2,y=3;
        else x=0,y=1;
        int cnt=(tr[lch].sz+tr[rch].sz)*2+1;
        tr[u].hs=x*pw[cnt];
        tr[u].hs+=tr[lch].hs*pw[cnt-tr[lch].sz*2];
        tr[u].hs+=tr[rch].hs*4+y;
    }

    int new_node() {
        return ++idx;
    }

    bool update(int &u,int v,int x,int bit,bool dir) {
        u=new_node();
        tr[u]=tr[v];
        bool del=0;

        if(bit>=0) {
            int cur=x>>bit&1;
            int &ch=tr[u].ch[cur];
            if(bit==0&&ch||update(ch,tr[v].ch[cur],x,bit-1,cur)&&tr[ch].sz==1) {
                tr[u].sz--;
                ch=0;
                del=1;
            }
        }

        tr[u].sz=tr[lch].sz+tr[rch].sz+1;
        hash(u,dir);
        return del;
    }

    int query(int u,int v,int bit) {
        auto equ=[&](int x,int y) {
            return tr[x].sz==tr[y].sz&&tr[x].hs==tr[y].hs;
        };
        if(bit==-1) return 0;
        if(!equ(lch,tr[v].ch[0])) return query(lch,tr[v].ch[0],bit-1);
        if(!equ(rch,tr[v].ch[1])) return 1<<bit|query(rch,tr[v].ch[1],bit-1);
        return 0;
    }

    #undef lch
    #undef rch
} trie;

void solve() {
    int n,m,bit=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],bit=max(bit,__lg(arr[i]));
    pw[0]=1;
    for(int i=1;i<N*(bit+1);i++) pw[i]=pw[i-1]*4;
    for(int i=1;i<=n;i++) trie.update(root[i], root[i-1], arr[i], bit, 0);

    int ans=0;
    cin>>m;
    while(m--) {
        int l,r;
        cin>>l>>r;
#ifdef ONLINE_JUDGE
        l^=ans,r^=ans;
#endif
        ans=trie.query(root[r], root[l-1], bit);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}