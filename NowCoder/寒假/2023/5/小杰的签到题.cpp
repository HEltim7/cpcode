#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e4+10;
int arr[N];

void solve() {
    int n,b;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    cin>>b;

    int ans=0;
    vector<int> q;
    for(int i=1;i<=n;i++) {
        sort(q.begin(),q.end(),greater<>());
        while(q.size()&&q.back()<=arr[i]) q.pop_back();
        // int cur=q.size()==3?
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