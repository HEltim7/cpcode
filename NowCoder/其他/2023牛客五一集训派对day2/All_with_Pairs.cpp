#include <algorithm>
#include <array>
#include <cassert>
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
constexpr int N=1e5+10,S=1e6+10;

template<typename I,typename L,I mod> struct Modint {
    I v;
    constexpr I pow(L b) const {
        L res=1,a=v;
        while(b) { if(b&1) res=res*a%mod; b>>=1; a=a*a%mod; }
        return res;
    }
    constexpr I inv() const { return pow(mod-2); }

    constexpr Modint &operator+=(const Modint &x) { v+=x.v; v-=v>=mod?mod:0; return *this; }
    constexpr Modint &operator-=(const Modint &x) { v-=x.v; v+=v<0?mod:0; return *this; }
    constexpr Modint &operator*=(const Modint &x) { v=L(1)*v*x.v%mod; return *this; }
    constexpr Modint &operator/=(const Modint &x) { v=L(1)*v*x.inv()%mod; return *this; }

    friend constexpr Modint operator+(Modint l,const Modint &r) { return l+=r; }
    friend constexpr Modint operator-(Modint l,const Modint &r) { return l-=r; }
    friend constexpr Modint operator*(Modint l,const Modint &r) { return l*=r; }
    friend constexpr Modint operator/(Modint l,const Modint &r) { return l/=r; }
    friend constexpr Modint operator-(Modint r) { r.v=mod-r.v; return r; }

    Modint operator++(int) { auto res=*this; ++*this; return res; }
    Modint operator--(int) { auto res=*this; --*this; return res; }
    Modint &operator++() { v=v==mod-1?0:v+1; return *this; }
    Modint &operator--() { v=v?v-1:mod-1; return *this; }

    constexpr bool operator< (const Modint &x) const { return v< x.v; }
    constexpr bool operator> (const Modint &x) const { return v> x.v; }
    constexpr bool operator<=(const Modint &x) const { return v<=x.v; }
    constexpr bool operator>=(const Modint &x) const { return v>=x.v; }
    constexpr bool operator==(const Modint &x) const { return v==x.v; }
    constexpr bool operator!=(const Modint &x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { is>>x.v; x=Modint(x.v); return is; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    constexpr Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
}; using Mint=Modint<int,long long,998244353>;
int cnt[S],res[S];

struct AhoCorasickAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Node {
        int link,cnt;
        int ch[A];
    };

    vector<Node> tr;
    int sz=0;

    int insert(string &s) {
        int root=0;
        for(auto x:s) {
            int c=x-B;
            if(!tr[root].ch[c]) 
                tr[root].ch[c]=new_node();
            root=tr[root].ch[c];
        }
        return root;
    }

    void build() {
        queue<int> q;
        for(int i=0;i<A;i++) 
            if(tr[0].ch[i]) {
                q.push(tr[0].ch[i]);

            }
        while(q.size()) {
            auto root=q.front();
            q.pop();
            for(int i=0;i<A;i++) {
                int &cur=tr[root].ch[i];
                int pre=tr[tr[root].link].ch[i];
                if(!cur) cur=pre;
                else {
                    tr[cur].link=pre;
                    q.push(cur);
                }
            }
        }
    }

    void count(string &s) {
        int u=0;
        for(char x:s) {
            int c=x-B;
            u=tr[u].ch[c];
        }
        while(u) {
            tr[u].cnt++;
            u=tr[u].link;
        }
    }

    void get_cnt(string &s) {
        for(int i=1,u=0;i<s.size();i++) {
            int c=s[i]-B;
            u=tr[u].ch[c];
            res[i]=cnt[i]=tr[u].cnt;
        }
    }

    int size() { return tr.size(); }
    int new_node() { tr.push_back({});return ++sz; }
    void clear() { tr.clear();tr.resize(1);sz=0; }

    AhoCorasickAutomaton() { tr.resize(1); }
    AhoCorasickAutomaton(int sz) { tr.reserve(sz+1);tr.push_back({}); }
} acam(N);

int link[S];
void kmp_build(string &t) {
    for(int i=2,j=0;i<t.size();i++) {
        while(j&&t[i]!=t[j+1]) j=link[j];
        if(t[i]==t[j+1]) j++;
        link[i]=j; 
    }
}

void solve() {
    int n;
    cin>>n;
    vector<string> vs(n);
    for(auto &s:vs) {
        cin>>s;
        acam.insert(s);
    }
    acam.build();
    for(auto &s:vs) acam.count(s);

    Mint ans;
    for(auto &s:vs) {
        s=" "+s;
        acam.get_cnt(s);
        kmp_build(s);
        for(int i=s.size()-1;i>=1;i--) {
            res[link[i]]-=cnt[i];
            ans+=1LL*res[i]*i*i;
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}