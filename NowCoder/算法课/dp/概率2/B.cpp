#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e5+10;
int pre[N];
LD dp[N];

void solve() {
    cout<<fixed<<setprecision(2);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>pre[i];
        pre[i]+=pre[i-1];
    }

    auto solve=[&](int m) {
        LD sum=0;
        for(int i=n,j=n;i>=1;i--) {
            while(pre[j]-pre[i-1]>m) sum-=dp[j--];
            if(j<i) {
                cout<<"YNOI is good OI!"<<endl;
                return;
            }
            dp[i]=(sum+dp[j+1])/(j-i+1)+1;
            sum+=dp[i];
        }
        cout<<dp[1]<<endl;
    };

    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        solve(in);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}