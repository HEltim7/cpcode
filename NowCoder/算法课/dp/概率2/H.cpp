#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=18;
LD a[N][N],dp[1<<N];
vector<int> st[N];

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    for(int i=0;i<1<<n;i++)
        st[__builtin_popcount(i)].push_back(i);

    dp[0]=1;
    for(int i=0;i<n-1;i++) {
        int left=n-i;
        const LD p=LD(2)/(left*(left-1));
        for(int j:st[i]) {
            for(int x=0;x<n;x++) {
                if(j&1<<x) continue;
                for(int y=x+1;y<n;y++) {
                    if(j&1<<y) continue;
                    dp[j|1<<x]+=p*a[y][x]*dp[j];
                    dp[j|1<<y]+=p*a[x][y]*dp[j];
                }
            }
        }
    }

    cout<<fixed<<setprecision(6);
    for(int i=0;i<n;i++) cout<<dp[((1<<n)-1)^(1<<i)]<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}