#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
int cnt[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        cnt[in]++;
    }

    vector<int> table;
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        table.push_back(in);
    }
    sort(table.begin(),table.end());

    vector<int> v;
    for(int i=1;i<=n;i++) if(cnt[i]) v.emplace_back(cnt[i]);
    sort(v.begin(),v.end());
    for(auto x:v) {
        
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