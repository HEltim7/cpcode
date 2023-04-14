#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=510;

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

int link[N];
string t;
Mint dp[N];
int minn[N];

void kmp_build(int n) {
    for(int i=2,j=0;i<=n;i++) {
        while(j&&t[i]!=t[j+1]) j=link[j];
        if(t[i]==t[j+1]) j++;
        link[i]=t[i+1]==t[j+1]?link[j]:j; 
    }
}

void solve() {
    string s;
    cin>>s>>t;
    t=" "+t;
    s=" "+s;
    int n=t.size()-1;
    kmp_build(n);

    vector<int> pos(1,0);
    for(int i=1,j=0;i<s.size();i++) {
        while(j&&s[i]!=t[j+1]) j=link[j];
        if(s[i]==t[j+1]) j++;
        if(j==n) {
            pos.push_back(i);
            j=link[j];
        }
    }

    if(pos.size()<=1) cout<<0<<' '<<1<<endl;
    else {
        dp[0]=1;
        for(int i=1;i<pos.size();i++) {
            dp[i]=0;
            minn[i]=N;
            int r=pos[i];
            int l=r-n+1;
            auto it=lower_bound(pos.begin(),pos.end(),l);
            if(it!=pos.end()&&it!=pos.begin()) {
                int R=*--it;
                int L=R-n+1;
                for(int j=i-1;j>=0&&pos[j]>=L;j--) {
                    if(pos[j]<l) minn[i]=min(minn[i],minn[j]+1);
                }
                for(int j=i-1;j>=0&&pos[j]>=L;j--) {
                    if(pos[j]<l&&minn[i]==minn[j]+1) {
                        dp[i]+=dp[j];
                    }
                }
            }
            else minn[i]=1,dp[i]=1;
        }

        int step=N;
        Mint ans=0;
        int last=pos.back()-n+1;
        for(int i=pos.size()-1;i>=0&&pos[i]>=last;i--) {
            step=min(step,minn[i]);
        }
        for(int i=pos.size()-1;i>=0&&pos[i]>=last;i--) {
            if(minn[i]==step) ans+=dp[i];
        }
        cout<<step<<' '<<ans<<endl;
    }   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}