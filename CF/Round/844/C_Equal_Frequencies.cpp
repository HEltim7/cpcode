#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,INF=1e9;
int tot[30],dp[30][30];
int pre[30][30];

int solve(int n,int ch) {
    if(n%ch) return INF;
    int num=n/ch;
    
    memset(dp, 0x3f, sizeof dp);
    dp[0][1]=abs(num-tot[0]);
    dp[0][0]=tot[0];
    for(int i=0;i<25;i++) {
        for(int j=0;j<=ch;j++) {
            if(dp[i][j]+tot[i+1]<dp[i+1][j]) {
                dp[i+1][j]=dp[i][j]+tot[i+1];
                pre[i+1][j]=j;
            }
            if(dp[i][j]+abs(num-tot[i+1])<dp[i+1][j+1]) {
                dp[i+1][j+1]=dp[i][j]+abs(num-tot[i+1]);
                pre[i+1][j+1]=j;
            }
        }
    }
    return dp[25][ch];
}

void solve() {
    int n;
    string s;
    cin>>n>>s;
    memset(tot, 0, sizeof tot);
    for(auto x:s) tot[x-'a']++;

    int minn=INF,cnt=0;
    string res;
    for(int i=1;i<=26;i++) {
        int t=solve(n,i);
        if(t<minn) {
            cnt=n/i;
            minn=t;
            int x=25,y=i;
            res.clear();
            while(x) {
                if(pre[x][y]<y) res.push_back(x+'a');
                y=pre[x][y];
                x--;
            }
            if(y) res.push_back('a');
        }
    }
    vector<int> v;
    for(auto x:res) tot[x-'a']-=cnt;
    for(int i=0;i<26;i++) if(tot[i]<0) v.emplace_back(i);

    int ans=0;
    for(auto &x:s) {
        if(tot[x-'a']>0) {
            ans++;
            tot[x-'a']--;
            int t=v.back();
            tot[t]++;
            x=t+'a';
            if(tot[t]>=0) v.pop_back();
        }
    }
    cout<<ans<<endl<<s<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}