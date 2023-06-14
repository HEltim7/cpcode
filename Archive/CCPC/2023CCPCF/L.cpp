#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
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
constexpr int N=2e6+32,S=5e3+10;
using BS=bitset<N>;
int cnt[N],ans[N];
BS dp[S]; ////////////////!!!!!!!!!!!!!!!!!!!!!!!!!

constexpr int M=1e6+16;
int prime[M],minp[M],pidx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++pidx]=i,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

vector<int> get_factor(int val) {
    vector<int> res;
    while(val>1) {
        int t=minp[val];
        int cnt=0;
        while(minp[val]==t) val/=t,cnt++;
        if(cnt&1) res.push_back(t);
    }
    return res;
}

void solve() {
    int n,k;
    cin>>n>>k;
    if(n==1) {
        if(k==1) cout<<1<<endl;
        else cout<<-1<<endl;
        return;
    }

    memset(cnt, 0, sizeof(int)*(n+1));
    ans[1]=1;
    k--;

    for(int i=2;i<=n;i++) {
        auto &&v=get_factor(i);
        if(v.empty()) k--;
        else {
            for(int x:v) {
                cnt[x]++;
            }
        }
    }

    // (id,val)
    vector<int> item;
    vector<pair<int,int>> rng;
    // cur 当前连续相同cnt的个数,l 最左侧的这种质数id
    for(int i=1,cur=1,l=0;i<=pidx&&prime[i]<=n;i++) {
        int x=prime[i];
        if(cnt[x]!=cnt[prime[i+1]]) {
            debug(x,cnt[x],cur);
            int tot=0;
            for(int j=1;j+tot<=cur;j<<=1) {
                item.emplace_back(j*cnt[x]);
                rng.emplace_back(l+tot+1,l+tot+j);
                tot+=j;
            }
            if(cur>tot) {
                item.emplace_back((cur-tot)*cnt[x]);
                rng.emplace_back(l+tot+1,l+cur);
            }
            cur=0;
            l=i;
        }
        cur++;
    }
    debug(item);
    debug(rng);

    int offset=N/2;
    for(int i=0;i<item.size();i++) {
        dp[i].reset();
        int mv=item[i];
        if(i==0) {
            dp[i][offset+mv]=1;
            dp[i][offset-mv]=1;
        }
        else {
            dp[i]|=dp[i-1]<<mv;
            dp[i]|=dp[i-1]>>mv;
        }
    }

    int t=item.size()-1;
    for(int i=0;i<=t;i++) {
        debug(i);
        for(int j=-10;j<=-1;j++) cerr<<dp[i][j+offset];
        cerr<<' '<<dp[i][offset]<<' ';
        for(int j=1;j<=10;j++) cerr<<dp[i][j+offset];
        cerr<<endl;
    }

    if(dp[t][offset+k]) {
        int idx=offset+k;
        for(int i=t;i>=0;i--) {
            int mv=item[i];
            int res=0;
            if(i) {
                // pos
                if(dp[i-1][idx-mv]) {
                    idx-=mv;
                    res=1;
                }
                // neg
                else {
                    assert(dp[i-1][idx+mv]);
                    idx+=mv;
                    res=-1;
                }
            }
            else {
                assert(dp[0][idx]);
                if(idx>offset) res=1;
                else res=-1;
            }
            for(int j=rng[i].first;j<=rng[i].second;j++) {
                ans[prime[j]]=res;
                debug(prime[j],res);
            }
        }

        ans[1]=1;
        for(int i=2;i<=n;i++) {
            if(!isnp[i]) continue;
            auto &&v=get_factor(i);
            ans[i]=1;
            for(int x:v) {
                ans[i]*=ans[x];
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
    }
    else {
        cout<<-1<<endl;
    }
}

int main() {
    get_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}