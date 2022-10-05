#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e2+10;
int pre[N];

void solve() {
    int n;
    cin>>n;
    bool flag=1;
    for(int i=1;i<=n;i++) {
        cin>>pre[i];
        if(i>=2&&pre[i]&&pre[i]<=pre[i-1]) flag=0;
        pre[i]+=pre[i-1];
    }
    if(!flag) {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=1;i<=n;i++) cout<<pre[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}