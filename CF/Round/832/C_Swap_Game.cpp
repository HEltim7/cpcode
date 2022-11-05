#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n,minn=1e9;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i],minn=min(minn,arr[i]);
    if(arr[1]==minn) cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}