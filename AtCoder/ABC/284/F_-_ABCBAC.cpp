#include <array>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e6+10;

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

mt19937 gen=mt19937(random_device{}());
vector<int> num={1000000007,1000000009,1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,1000000123,1000000181,1000000207,1000000223,1000000241,1000000271,1000000289,1000000297,1000000321,1000000349,1000000363,1000000403,1000000409,1000000411,1000000427,1000000433,1000000439,1000000447,1000000453,1000000459,1000000483,1000000513,1000000531,1000000579,1000000607,1000000613,1000000637,1000000663,1000000711,1000000753,1000000787,1000000801,1000000829,1000000861,1000000871,1000000891,1000000901,1000000919,1000000931,1000000933,1000000993,1000001011};
int random_prime() {
    shuffle(num.begin(), num.end(), gen);
    int res=num.back();
    num.pop_back();
    return res;
}

struct HashArray {
    constexpr static int base=131;
    vector<Hint> arr,pw;

    void push_back(int x) {
        arr.push_back(arr.back()*base+x);
        pw.push_back(pw.back()*base);
    }

    void append(string &s) { for(auto x:s) push_back(x); }
    void append(vector<int> &s) { for(auto x:s) push_back(x); }

    Hint query(int l,int r) {
        return arr[r]-arr[l-1]*pw[r-l+1];
    }

    void clear() { arr.clear(),pw.clear();arr.push_back(0),pw.push_back(1); }
    
    HashArray() { clear(); };
    HashArray(int sz) {
        clear();
        arr.reserve(sz),pw.reserve(sz);
    };
};

void solve() {
    for(int i=0;i<HASHCNT;i++) mod[i]=random_prime();
    HashArray h1(N),h2(N);
    int n;
    string s;
    cin>>n>>s;
    h1.append(s);
    reverse(s.begin(),s.end());
    h2.append(s);

    for(int l=1;l<=n+1;l++) {
        int r=l+n-1;
        int L=2*n-r+1,R=2*n-l+1;
        Hint x=h1.query(1, l-1)*h1.pw[2*n-r]+h1.query(r+1,2*n);
        Hint y=h2.query(L, R);
        if(x==y) {
            string ans;
            for(int i=L;i<=R;i++) ans.push_back(s[i-1]);
            cout<<ans<<endl<<l-1<<endl;
            return;
        }
    }
    cout<<-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}