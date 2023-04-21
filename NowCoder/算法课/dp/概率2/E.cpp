#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e3+10;
LD dp[N][N][2];

void solve() {
    int w,b;
    cin>>w>>b;

    for(int i=0;i<=w;i++) {
        for(int j=0;j<=b;j++) {
            LD pw=LD(i)/(i+j);
            LD pb=LD(j)/(i+j);
            
            if(i==0) dp[i][j][0]=0;
            else dp[i][j][0]=pw+(1-dp[i][j-1][1])*pb;

            if(i==0||i+j<=2) dp[i][j][1]=1;
            else {
                if(i) dp[i][j][1]+=pw;
                if(j>=2) dp[i][j][1]+=pb*LD(j-1)/(i+j-1)*(1-dp[i][j-2][0]);
                if(i&&j) dp[i][j][1]+=pb*LD(i)/(i+j-1)*(1-dp[i-1][j-1][0]);
            }
        }
    }
    cout<<fixed<<setprecision(12)<<dp[w][b][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}