#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;

void solve() {
    vector<int> arr;
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr.push_back(in);
    }
    sort(arr.begin(),arr.end(),greater<>());

    for(int i=0;i<n;i++) cout<<arr[i]<<" \n"[i==n-1];
    for(int i=1;i<n;i++) cout<<1<<' ';
    cout<<m-(n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}