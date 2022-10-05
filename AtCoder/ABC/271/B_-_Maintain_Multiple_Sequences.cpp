#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
vector<int> arr[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        int s;
        cin>>s;
        arr[i].resize(s);
        for(int j=0;j<s;j++) cin>>arr[i][j];
    }
    while(q--) {
        int s,t;
        cin>>s>>t;
        cout<<arr[s][t-1]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}