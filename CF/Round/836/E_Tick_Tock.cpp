#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

template<typename I,typename L,const int &mod> struct Modint {
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

    bool operator< (const Modint&x) const { return v< x.v; }
    bool operator> (const Modint&x) const { return v> x.v; }
    bool operator<=(const Modint&x) const { return v<=x.v; }
    bool operator>=(const Modint&x) const { return v>=x.v; }
    bool operator==(const Modint&x) const { return v==x.v; }
    bool operator!=(const Modint&x) const { return v!=x.v; }

    friend istream &operator>>(istream &is,Modint &x) { return is>>x.v; }
    friend ostream &operator<<(ostream &os,const Modint &x) { return os<<x.v; }

    Modint(L x=0): v((x%=mod)<0?x+mod:x) {}
};
constexpr int mod=1e9+7;
int h;
using Mint=Modint<int,int,h>;

void solve() {
    int n,m;
    cin>>n>>m>>h;
    bool rev=0;
    if(n>m) swap(n,m),rev=1;
    auto grid=vector<vector<int>>(n+1,vector<int>(m+1));
    
    if(!rev) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>grid[i][j];
    else for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cin>>grid[j][i];
    auto rowv=vector<int>(n+1,-1);
    auto colv=vector<int>(m+1,-1);
    
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if(rowv[i]!=-1) continue;
        bool flag=0;
        for(int j=1;j<=m;j++) if(grid[i][j]!=-1) flag=1;
        if(!flag) continue;
        cnt++;
        
        queue<int> q;
        q.push(i);
        rowv[i]=0;
        while(q.size()) {
            int r=q.front();
            q.pop();

            auto check=[&](int r,int c) {
                bool res=Mint(rowv[r]+colv[c]+grid[r][c])!=0;
                if(res) cout<<0<<endl;
                return res;
            };

            for(int c=1;c<=m;c++) {
                if(grid[r][c]!=-1) {
                    if(colv[c]==-1) colv[c]=Mint(h-(rowv[r]+grid[r][c])).v;
                    else if(check(r,c)) return;

                    for(int k=1;k<=n;k++) {
                        if(grid[k][c]!=-1) {
                            if(rowv[k]==-1) {
                                q.push(k);
                                flag=1;
                                rowv[k]=Mint(h-(colv[c]+grid[k][c])).v;
                            }
                            else if(check(k,c)) return;
                        }
                    }
                }
                
            }
        }
    }

    for(int i=1;i<=n;i++) if(rowv[i]==-1) cnt++;
    for(int i=1;i<=m;i++) if(colv[i]==-1) cnt++;
    cnt--;
    cout<<Modint<int,LL,mod>(h).pow(cnt)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}