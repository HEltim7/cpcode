#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstdlib>
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

constexpr int N=310;
using BS=bitset<N*N>;
int arr[N];
BS dp[N];

void solve() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>arr[i],sum+=arr[i];
    dp[0][0]=1;
    for(int i=1;i<=n;i++) {
        dp[i]=dp[i-1]|dp[i-1]<<arr[i];
    }

    bool fi=0;
    if(sum&1||!dp[n][sum>>1]) fi=1;
    cout<<(fi?"First":"Second")<<endl;

    if(fi) {
        set<int> st;
        for(int i=1;i<=n;i++) st.insert(i);
        while(st.size()) {
            int idx=*st.begin();
            cout<<idx<<endl;
            int in;
            cin>>in;
            if(!in) return;
            int t=min(arr[idx],arr[in]);
            if((arr[idx]-=t)==0) st.erase(idx);
            if((arr[in]-=t)==0) st.erase(in);
        }
    }
    else {
        set<int> l,r;
        for(int i=n,cur=sum>>1;i>=1;i--) {
            int idx=cur-arr[i];
            if(idx>=0&&dp[i-1][idx]) {
                cur=idx;
                l.insert(i);
            }
        }
        for(int i=1;i<=n;i++) if(l.find(i)==l.end()) r.insert(i);
        debug(l,r);

        for(;;) {
            int in;
            cin>>in;
            if(!in) return;
            if(l.find(in)!=l.end()) {
                int idx=*r.begin();
                int t=min(arr[in],arr[idx]);
                if((arr[in]-=t)==0) l.erase(in);
                if((arr[idx]-=t)==0) r.erase(idx);
                cout<<idx<<endl;
            }
            else {
                int idx=*l.begin();
                int t=min(arr[in],arr[idx]);
                if((arr[in]-=t)==0) r.erase(in);
                if((arr[idx]-=t)==0) l.erase(idx);
                cout<<idx<<endl;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}