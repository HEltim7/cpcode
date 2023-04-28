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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int p[N],aim[N];
int ans[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++) cin>>p[i];
    for(int i=1;i<=k;i++) cin>>aim[i];
    for(int i=1;i<=k;i++) {
        if(aim[i]>p[i]||aim[i]-aim[i-1]>p[i]-p[i-1]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    
    vector<pair<int,int>> v;
    v.emplace_back(p[1],aim[1]);
    for(int i=2;i<=k;i++) {
        if(aim[i]==v.back().second) v.back().first=p[i];
        else v.emplace_back(p[i],aim[i]);
    }
    k=v.size();
    for(int i=0;i<k;i++) tie(p[i+1],aim[i+1])=v[i];
    debug(p,1,k);
    debug(aim,1,k);

    int tot=0;
    int c=0;
    for(int i=1;i<=aim[1]-3;i++) ans[i]=0,tot++;
    tot+=3;
    for(int i=aim[1]-3+1;i<=p[1];i++) {
        ans[i]=c;
        c=(c+1)%3;
    }
    assert(tot==aim[1]);
    int lastc=ans[p[1]];

    for(int i=2,c=(lastc+1)%3,ch=3;i<=k;i++,ch++) {
        for(int j=p[i-1]+1;j<=p[i];j++) {
            if(aim[i]>tot) {
                ans[j]=ch;
                tot++;
            }
            else {
                lastc=c;
                ans[j]=c;
                c=(c+1)%3;
            }
        }
        assert(tot==aim[i]);
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<char(ans[i]+'a');
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}