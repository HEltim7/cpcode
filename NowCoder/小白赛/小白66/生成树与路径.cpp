#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;

void solve() {
    int n,m;
    cin>>n>>m;
    for(int k=1,idx=0;idx<m;k++) {
        for(int i=1;i+k<=n&&idx<m;i++) {
            cout<<i<<' '<<i+k<<' '<<++idx<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}