#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
int dp[N][N];

void solve() {
    string s;
    cin>>s;
    int slen=s.size();

    auto check=[&](int a,int b) {
        if(s[a]<s[b]) return 1;
        if(s[a]>s[b]) return -1;
        return 0;
    };

    for(int len=2;len<=slen;len+=2) {
        for(int i=0;i<slen;i++) {
            int j=i+len-1;
            if(len==2) {
                dp[i][j]=max(check(i,j),check(j,i));
                continue;
            }
            int L,R;
            if(dp[i+2][j]) L=dp[i+2][j];
            else L=check(i,i+1);
            if(dp[i+1][j-1]) R=dp[i+1][j-1];
            else R=check(i,j);
            dp[i][j]=min(L,R);

            if(dp[i+1][j-1]) L=dp[i+1][j-1];
            else L=check(j,i);
            if(dp[i][j-2]) R=dp[i][j-2];
            else R=check(j,j-1);
            dp[i][j]=max(dp[i][j],min(L,R));
        }
    }
    
    if(dp[0][slen-1]==1) cout<<"Alice"<<endl;
    else if(dp[0][slen-1]==0) cout<<"Draw"<<endl;
    else cout<<"Bob"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}