#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;

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
    static_assert(0ULL+mod+mod-2<1ULL<<(sizeof(I)*8-1), "Modint overflow");
    static_assert(1ULL*(mod-1)*(mod-1)<1ULL<<(sizeof(L)*8-1), "Modint overflow");
    
}; using Mint=Modint<int,long long,int(1e9+7)>;

Mint dp[N],g[N];

struct PalindromeAutomaton {
    const static int A=26;
    const static char B='a';
    struct Node {
        int len,link;
        int ch[A];
        int dif,slink;
    };
    vector<Node> node;
    string str;
    int last;

    int new_node(int len) {
        node.push_back({len});
        return node.size()-1;
    }
    
    void clear() {
        node.clear();
        last=0;
        str="!";
        new_node(0);
        new_node(-1);
        node[0].link=1;
    }

    int getfail(int x) {
        while(str[str.size()-node[x].len-2]!=str.back()) x=node[x].link;
        return x;
    }

    void extend(char x) {
        str.push_back(x);
        int c=x-B;
        int pre=getfail(last);
        if(!node[pre].ch[c]) {
            int cur=new_node(node[pre].len+2);
            int lk=node[getfail(node[pre].link)].ch[c];
            node[cur].link=lk;
            node[pre].ch[c]=cur;
            node[cur].dif=node[cur].len-node[lk].len;
            node[cur].slink=node[cur].dif==node[lk].dif?node[lk].slink:lk;
        }
        last=node[pre].ch[c];
        
        int i=str.size()-1;
        for(int cur=last;cur>=2;cur=node[cur].slink) {
            auto &t=node[cur];
            g[cur]=dp[i-(node[t.slink].len+t.dif)];
            if(t.dif==node[t.link].dif) g[cur]+=g[t.link];
            if(i%2==0) dp[i]+=g[cur];
        }
    }

    void build(string &s) { for(auto x:s) extend(x); }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { str.reserve(sz),node.reserve(sz),clear(); }
} pam;

void solve() {
    string s,t;
    cin>>s;
    if(s.size()&1) {
        cout<<0<<endl;
        return;
    }
    for(int i=0,j=s.size()-1;i<j;i++,j--)
        t.push_back(s[i]),t.push_back(s[j]);

    dp[0]=1;
    pam.build(t);
    cout<<dp[s.length()];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}