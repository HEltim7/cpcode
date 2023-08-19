#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int m;
    cin>>m;
    vector<int> arr(m+1);
    for(int i=1;i<=m;i++) cin>>arr[i];
    int sum=accumulate(arr.begin(),arr.end(),0);
    for(int i=1,pre=0;i<=m;i++) {
        if(pre+arr[i]>=(sum+1)/2) {
            cout<<i<<' '<<(sum+1)/2-pre;
            return;
        }
        pre+=arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}