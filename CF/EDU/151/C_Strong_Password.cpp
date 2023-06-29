#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=3e5+10,M=10;
int s[N],l[N],r[N],ne[N][M+2];
bool dp[N][M+2];

void solve() {
    string str;
    cin>>str;
    int n=str.size();
    str=" "+str;
    for(int i=1;i<=n;i++) s[i]=str[i]-'0';

    int m;
    cin>>m;
    string ls,rs;
    cin>>ls>>rs;
    for(int i=0;i<m;i++) l[i+1]=ls[i]-'0';
    for(int i=0;i<m;i++) r[i+1]=rs[i]-'0';

    memset(ne[n+1], 0, sizeof ne[n+1]);
    for(int i=n;i>=1;i--) {
        for(int j=0;j<=M;j++) ne[i][j]=ne[i+1][j];
        ne[i][s[i]]=i;
    }

    for(int i=0;i<=n;i++) memset(dp[i], 0, sizeof dp[i]);
    dp[0][0]=1;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<m;j++) {
            if(dp[i][j]) {
                for(int k=l[j+1];k<=r[j+1];k++) {
                    int x=ne[i+1][k];
                    if(!x) {
                        cout<<"YES"<<endl;
                        return;
                    }
                    dp[x][j+1]=1;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}