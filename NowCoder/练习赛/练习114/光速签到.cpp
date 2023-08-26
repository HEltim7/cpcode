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
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &x:arr) cin>>x;
    sort(arr.begin(),arr.end(),greater<>());
    if(arr.back()!=0) {
        cout<<-1<<endl;
        return;
    }
    for(int x:arr) cout<<x;
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}