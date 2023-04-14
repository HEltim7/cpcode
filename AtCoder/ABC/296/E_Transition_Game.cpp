#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],ind[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],ind[arr[i]]++;
    
    int ans=n;
    queue<int> q;
    for(int i=1;i<=n;i++) if(!ind[i]) q.push(i);
    while(q.size()) {
        int u=q.front();
        q.pop();
        ans--;
        if(!--ind[arr[u]]) q.push(arr[u]);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}