#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10;
LL dp[N],pret[N],prec[N];

void solve() {
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) {
        cin>>pret[i]>>prec[i];
        pret[i]+=pret[i-1];
        prec[i]+=prec[i-1];
    }
    memset(dp+1, 0x3f, sizeof(LL)*n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            dp[i]=min(dp[i],dp[j]+(prec[i]-prec[j])*pret[i]+(prec[n]-prec[j])*s);
    cout<<dp[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}