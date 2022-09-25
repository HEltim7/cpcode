#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,c;
    cin>>n>>c;
    vector<int>cnt(110);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        cnt[in]++;
    }
    int res=0;
    for(int i=0;i<=100;i++) res+=min(cnt[i],c);
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}