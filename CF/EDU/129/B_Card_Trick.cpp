#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m,in;
    LL b=0;
    vector<int> arr;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in,arr.push_back(in);
    cin>>m;
    for(int i=1;i<=m;i++) cin>>in,b+=in;
    b%=n;
    cout<<arr[b]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}