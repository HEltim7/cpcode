#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;

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
    
}; using Mint=Modint<int,long long,998244353>;

Mint pos[N],neg[N];


void solve() {
    int n;
    cin>>n;
    set<int> st;
    for(int i=0;i<=3e5;i++) st.insert(i);
    pos[1]=1;
    for(int i=1;i<=n;i++) {
        pos[i]=2*pos[i-1]+neg[i-1];
        neg[i]=neg[i-1]+pos[i-1];
    }

    Mint ans;
    for(int i=1;i<=n;i++) {
        int l,r;
        cin>>l>>r;
        while(l<=r) {
            auto it=st.lower_bound(l);
            if(it!=st.end()) {
                if(*it<=r) {
                    if(i==1) ans+=pos[n-i+1];
                    else ans+=Mint(3).pow(i-2);
                    l=*it+1;
                    st.erase(it);
                }
            }
            else break;
        }
    }


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}