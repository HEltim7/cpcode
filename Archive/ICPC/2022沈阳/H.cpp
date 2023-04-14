#include <set>
#include <array>
#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;

constexpr int HASHCNT=4;
array<LL,HASHCNT> mod;
template<int size,typename I=LL,typename L=__int128,const array<I,size> &p=mod> struct Hashint {
    array<I,size> v;
    I _pow(int i,L b) const {
        L res=1,a=v[i];
        while(b) { if(b&1) res=res*a%p[i]; b>>=1; a=a*a%p[i]; }
        return res;
    }
    I _inv(int i) const { return _pow(i,p[i]-2); }
    Hashint pow(L b) {
        Hashint res;
        for(int i=0;i<size;i++) res[i]=_pow(i,b);
        return res;
    }

    Hashint &operator+=(const Hashint &x) { for(int i=0;i<size;i++) v[i]+=x[i],v[i]-=v[i]>=p[i]?p[i]:0; return *this; }
    Hashint &operator-=(const Hashint &x) { for(int i=0;i<size;i++) v[i]-=x[i],v[i]+=v[i]<0?p[i]:0; return *this; }
    Hashint &operator*=(const Hashint &x) { for(int i=0;i<size;i++) v[i]=L(1)*v[i]*x[i]%p[i]; return *this; }
    Hashint &operator/=(const Hashint &x) { for(int i=0;i<size;i++) v[i]=L(1)*v[i]*x._inv(i)%p[i]; return *this; }

    friend Hashint operator+(Hashint l,const Hashint &r) { return l+=r; }
    friend Hashint operator-(Hashint l,const Hashint &r) { return l-=r; }
    friend Hashint operator*(Hashint l,const Hashint &r) { return l*=r; }
    friend Hashint operator/(Hashint l,const Hashint &r) { return l/=r; }
    
    Hashint operator++(int) { auto res=*this; *this+=1; return res; }
    Hashint operator--(int) { auto res=*this; *this-=1; return res; }
    Hashint operator-  () { return *this*-1; }
    Hashint &operator++() { return *this+=1; }
    Hashint &operator--() { return *this-=1; }

    bool operator< (const Hashint&x) const { return v< x.v; }
    bool operator> (const Hashint&x) const { return v> x.v; }
    bool operator<=(const Hashint&x) const { return v<=x.v; }
    bool operator>=(const Hashint&x) const { return v>=x.v; }
    bool operator==(const Hashint&x) const { return v==x.v; }
    bool operator!=(const Hashint&x) const { return v!=x.v; }

    auto &operator[](int i) { return v[i]; }
    auto &operator[](int i) const { return v[i]; }

    Hashint(L x=0) { for(int i=0;i<size;i++) v[i]=(x%p[i]+p[i])%p[i]; }
}; using Hint=Hashint<HASHCNT>;

set<Hint> st;
vector<pair<int,Hint>> hashv;
Hint pw[N];

struct PalindromeAutomaton {
    constexpr static int A=26;
    constexpr static char B='a';
    struct Node {
        int len,link;
        int cnt;
        int ch[A];
        bool mark;
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
            node[cur].link=node[getfail(node[pre].link)].ch[c];
            node[pre].ch[c]=cur;
        }
        last=node[pre].ch[c];
        node[last].cnt++;
    }

    void cal(int u,Hint val,int len) {
        for(int i=0;i<A;i++) {
            if(node[u].ch[i]) {
                Hint t=val*31+(i+1)*pw[len+1]+(i+1);
                hashv.push_back({len+2,t});
                cal(node[u].ch[i],t,len+2);
            }
        }
    }

    void build(string &s) { for(auto x:s) extend(x); last=0; str="!"; }
    int size() { return node.size(); }

    PalindromeAutomaton() { clear(); }
    PalindromeAutomaton(int sz) { str.reserve(sz),node.reserve(sz),clear(); }
} pam(N);

mt19937 gen=mt19937(random_device{}());
vector<LL> num={1000000000000000003,1000000000000000009,1000000000000000031,1000000000000000079,1000000000000000177,1000000000000000183,1000000000000000201,1000000000000000283,1000000000000000381,1000000000000000387,1000000000000000507,1000000000000000523,1000000000000000583,1000000000000000603,1000000000000000619,1000000000000000621,1000000000000000799,1000000000000000841,1000000000000000861,1000000000000000877,1000000000000000913,1000000000000000931,1000000000000000997,1000000000000001093,1000000000000001191,1000000000000001267,1000000000000001323,1000000000000001347,1000000000000001359,1000000000000001453,1000000000000001459,1000000000000001537,1000000000000001563,1000000000000001593,1000000000000001659,1000000000000001683,1000000000000001729,1000000000000001743,1000000000000001771,1000000000000001827,1000000000000001879,1000000000000001953,1000000000000002049,1000000000000002097,1000000000000002137,1000000000000002217,1000000000000002271,1000000000000002319,1000000000000002481,1000000000000002493};
LL random_prime() {
    shuffle(num.begin(), num.end(), gen);
    LL res=num.back();
    num.pop_back();
    return res;
}

void solve() {
    for(int i=0;i<HASHCNT;i++) mod[i]=random_prime();

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        pam.build(s);
    }
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*31;
    pam.cal(0, 0, 0);
    for(int i=0;i<pam.A;i++) {
        if(pam.node[1].ch[i]) {
            hashv.push_back({1,i+1});
            pam.cal(pam.node[1].ch[i],i+1,1);
        }
    }

    sort(hashv.begin(),hashv.end());
    for(auto &[len,x]:hashv) st.insert(x);

    LL ans=0;
    for(auto &[len,x]:hashv) {
        int res=0;
        auto cur=x;
        while(st.count(cur)) {
            res++;
            st.erase(cur);
            cur=cur*pw[len]+x;
        }
        ans+=1LL*res*res;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}