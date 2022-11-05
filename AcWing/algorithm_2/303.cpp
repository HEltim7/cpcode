#pragma GCC optimize("O2")
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,P=1e2+10;
vector<pair<LL,LL>> que[P];
int idxx[P];
LL d[N],s[N],suf1[N],suf2[N],ans[P];

LL dp(int m,int p) {
    que[0].emplace_back(0,suf2[1]);
    for(int i=1;i<=m;i++) {
        for(int j=min(i,p);j>=1;j--) {
            auto &last=que[j-1];
            auto &cur=que[j];
            auto &idx=idxx[j-1];

            assert(idx<last.size());
            auto [x,y]=last[idx];
            LL k=-suf1[i];
            LL b=y-k*x;
            while(idx+1<last.size()) {
                auto [x,y]=last[idx+1];
                if(y-k*x<=b) {
                    b=y-k*x;
                    idx++;
                }
                else break;
            }
            
            ans[j]=b-suf2[i]-(i-1)*suf1[i];
            x=i;
            y=ans[j]+suf2[i+1];
        
            while(cur.size()>=2) {
                auto [xl,yl]=cur[cur.size()-2];
                auto [xr,yr]=cur[cur.size()-1];
                if((y-yr)*(x-xl)<=(y-yl)*(x-xr)) cur.pop_back();
                else break;
            }
            cur.emplace_back(x,y);
        }
    }
    return ans[min(m,p)];
}

void solve() {
    LL ans=0;
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=2;i<=n;i++) cin>>d[i],d[i]+=d[i-1];
    for(int i=1,h,t;i<=m;i++) cin>>h>>t,s[i]=t-d[h];
    sort(s+1,s+1+m);
    for(int i=m;i>=1;i--) suf1[i]=s[m]-s[i];
    for(int i=m;i>=1;i--) suf2[i]=suf1[i]+suf2[i+1];
    cout<<ans+dp(m,p)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}