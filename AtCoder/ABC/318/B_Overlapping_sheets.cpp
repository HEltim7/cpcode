#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
constexpr int N=110;
bool mark[N][N];

void solve() {
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a++,c++;
        for(int j=a;j<=b;j++) {
            for(int k=c;k<=d;k++) {
                if(!mark[j][k]) ans++;
                mark[j][k]=1;
            }
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}