#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL pre[N];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>pre[i];
    sort(pre+1,pre+1+n,greater<LL>());
    for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
    while(q--) {
        int x,y;
        cin>>x>>y;
        cout<<pre[x]-pre[x-y]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}