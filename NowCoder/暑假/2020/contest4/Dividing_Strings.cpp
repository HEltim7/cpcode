#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <iterator>
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
constexpr int N=1e5+10,INF=10;

int left0[N],left9[N];
int dp[N][100];

void solve() {
    int n;
    string s;
    cin>>n>>s;
    vector<int> num;
    for(auto x:s) num.push_back(x-'0');

    int maxlen=0;
    for(int i=1;i<n;i++) {
        if(num[i]==0) {
            if(num[i-1]==0) left0[i]=left0[i-1];
            else left0[i]=i;
            maxlen=max(maxlen,i-left0[i]+1);
        }
        if(num[i]==9) {
            if(num[i-1]==9) left9[i]=left9[i-1];
            else left9[i]=i;
        }
    }

    int ans=9;
    // 暴力处理len=1的情况
    for(int i=0,maxx=0,minn=9;i<n;i++) {
        maxx=max(maxx,num[i]);
        minn=min(minn,num[i]);
        if(i+1==n) ans=min(ans,maxx-minn);
    }

    if(num.front()==0) {
        cout<<ans<<endl;
        return;
    }

    // 暴力处理len=2且允许不等长的情况
    auto bf=[&]() {
        if(n<=2) return INF;
        for(int i=0;i<n;i++) memset(dp[i], 0, sizeof dp[i]);
        for(int i=10;i<=99;i++) {
            dp[0][i]=num[0];
        }
        for(int i=10,cur=num[0]*10+num[1];i<=99;i++) {
            if(cur<=i&&num[0]) dp[1][i]=cur;
            else dp[1][i]=min(num[0],num[1]);
        }

        for(int i=2;i<n;i++) {
            int cur=num[i-1]*10+num[i];
            for(int j=10;j<=99;j++) {
                dp[i][j]=max(dp[i][j],min(dp[i-1][j],num[i]));
                if(cur<=j&&num[i-1]) dp[i][j]=max(dp[i][j],min(dp[i-2][j],cur));
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        int ans=100;
        for(int i=10;i<=99;i++) ans=min(ans,i-dp[n-1][i]);
        return ans;
    };

    // 处理len>=3且不允许不等长的情况
    auto samelen=[&](int len) {
        if(n%len) return INF;
        int maxlen=0;
        for(int i=0;i<len;i++) {
            bool good=1;
            for(int l=0;l<n;l+=len) {
                if(num[l+i]!=num[i]) {
                    good=0;
                    break;
                }
            }
            if(!good) break;
            maxlen++;
        }

        if(len-maxlen<=2) {
            int maxx=0,minn=1e9;
            for(int i=0;i<n;i+=len) {
                int r=i+len-1;
                int cur=num[r-1]*10+num[r];
                maxx=max(maxx,cur);
                minn=min(minn,cur);
            }
            return maxx-minn;
        }
        else {
            int midv=-1;
            int last0=0,last9=9;
            for(int i=0;i<n;i+=len) {
                int mid=i+maxlen;
                int r=i+len-1;
                if(num[r-1]==0) {
                    if(midv==-1) midv=num[mid];
                    else if(midv!=num[mid]) return INF;
                    if(left0[r-1]!=mid+1) return INF;
                    else last0=max(last0,num[r]);
                }
                else if(num[r-1]==9) {
                    if(midv==-1) midv=num[mid]+1;
                    else if(midv!=num[mid]+1) return INF;
                    if(left9[r-1]!=mid+1) return INF;
                    else last9=min(last9,num[r]);
                }
                else return INF;
            }
            return last0-last9+10;
        }
    };

    // 处理len>=3且允许不等长的情况
    auto diflen=[&](int len) {
        int idx=0;
        bool has0=0,has9=0;
        int last0=0,last9=9;

        while(idx<n) {
            int l=idx,r=l+len-1;
            if(num[l]==0) return INF;
            if(r<n&&num[r-1]==0) {
                has0=1;
                if(left0[r-1]!=l+1||num[l]!=1) return INF;
                last0=max(last0,num[r]);
            }
            else if(r-1<n&&num[r-2]==9) {
                r--;
                has9=1;
                if(left9[r-1]>l) return INF;
                last9=min(last9,num[r]);
            }
            else return INF;
            idx=r+1;
        }
        if(!has0||!has9) return INF;
        return last0-last9+10;
    };

    ans=min(ans,bf());
    for(int len=3;len<=(n+1)/2&&ans;len++) {
        ans=min(ans,samelen(len));
        ans=min(ans,diflen(len));
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}