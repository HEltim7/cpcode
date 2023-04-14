#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],cnt[N];
vector<int> bit[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) bit[i].clear();
    for(int i=1;i<=n;i++) {
        int k;
        cin>>k;
        bit[i].resize(k);
        for(auto &x:bit[i]) cin>>x,cnt[x]++;
    }

    bool res=0;
    for(int i=1;i<=n;i++) {
        bool flag=1;
        for(auto x:bit[i]) if(cnt[x]==1) flag=0;
        res|=flag;
    }

    for(int i=1;i<=n;i++) for(auto x:bit[i]) cnt[x]--;
    cout<<(res?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}