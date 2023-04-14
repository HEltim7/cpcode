#include <set>
#include <array>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],cnt[N];
vector<int> adj[N];

constexpr int HASHCNT=2;
array<int,HASHCNT> mod;
template<int size,typename I=int,typename L=long long,const array<I,size> &p=mod> struct Hashint {
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

    bool operator< (const Hashint &x) const { return v< x.v; }
    bool operator> (const Hashint &x) const { return v> x.v; }
    bool operator<=(const Hashint &x) const { return v<=x.v; }
    bool operator>=(const Hashint &x) const { return v>=x.v; }
    bool operator==(const Hashint &x) const { return v==x.v; }
    bool operator!=(const Hashint &x) const { return v!=x.v; }

    auto &operator[](int i) { return v[i]; }
    auto &operator[](int i) const { return v[i]; }

    Hashint(L x=0) { for(int i=0;i<size;i++) v[i]=(x%p[i]+p[i])%p[i]; }
}; using Hint=Hashint<HASHCNT>;

mt19937 gen=mt19937(random_device{}());
vector<int> num{0x3b9aca07,0x3b9aca09,0x3b9aca15,0x3b9aca21,0x3b9aca57,0x3b9aca5d,0x3b9aca61,0x3b9aca67,0x3b9aca7b,0x3b9acab5,0x3b9acacf,0x3b9acadf,0x3b9acaf1,0x3b9acb0f,0x3b9acb21,0x3b9acb29,0x3b9acb41,0x3b9acb5d,0x3b9acb6b,0x3b9acb93,0x3b9acb99,0x3b9acb9b,0x3b9acbab,0x3b9acbb1,0x3b9acbb7,0x3b9acbbf,0x3b9acbc5,0x3b9acbcb,0x3b9acbe3,0x3b9acc01,0x3b9acc13,0x3b9acc43,0x3b9acc5f,0x3b9acc65,0x3b9acc7d,0x3b9acc97,0x3b9accc7,0x3b9accf1,0x3b9acd13,0x3b9acd21,0x3b9acd3d,0x3b9acd5d,0x3b9acd67,0x3b9acd7b,0x3b9acd85,0x3b9acd97,0x3b9acda3,0x3b9acda5,0x3b9acde1,0x3b9acdf3};
int random_prime() {
    shuffle(num.begin(), num.end(), gen);
    int res=num.back();
    num.pop_back();
    return res;
}

int base;
set<Hint> acc;
Hint hsh[N];

Hint dfs1(int u,int fa) {
    Hint res=1;
    for(int v:adj[u]) {
        if(v!=fa) {
            res+=dfs1(v,u)*base;
        }
    }
    hsh[u]=res;
    return res;
}

vector<int> ans;
void dfs2(int u,int fa) {
    if(acc.count(hsh[u])) ans.push_back(u);
    int res=0;
    for(int v:adj[u]) {
        if(v!=fa) {
            Hint sum=(hsh[u]-hsh[v]*base)*base;
            hsh[v]+=sum;
            dfs2(v,u);
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) cin>>arr[i],cnt[arr[i]]++;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Hint cur=1,sum=0;
    for(int i=0;i<n;i++) {
        sum+=cur*cnt[i];
        cur*=base;
    }

    cur=1;
    for(int i=0;i<n;i++) {
        acc.insert(sum+cur);
        cur*=base;
    }
    
    dfs1(1,0);
    dfs2(1,0);
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(int x:ans) cout<<x<<' ';
}

int main() {
    base=(gen()>>2)+N;
    for(int i=0;i<HASHCNT;i++) mod[i]=random_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}