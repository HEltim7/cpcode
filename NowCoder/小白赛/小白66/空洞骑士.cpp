#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e9;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.begin(),arr.end());

    int s=0,t=N,dis=N;
    if(arr.back()*2-1>dis) s=0,t=1,dis=arr.back()*2-1;
    if((N-arr.front())*2-1>dis) s=N,t=N-1;

    cout<<s<<' '<<t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}