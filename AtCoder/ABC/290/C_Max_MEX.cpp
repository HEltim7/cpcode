#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &x:arr) cin>>x;
    sort(arr.begin(),arr.end());

    int pre=-1;
    for(auto x:arr) {
        if(x==pre+1&&k) {
            pre++;
            k--;
        }
    }
    cout<<pre+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}