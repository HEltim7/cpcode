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
    vector<int> arr(n+2),hor(n+2);
    for(int i=1;i<=n;i++) cin>>arr[i];
    if(arr[1]>n) {
        cout<<"NO"<<endl;
        return;
    }

    for(int i=1;i<=n;i++) hor[1]++,hor[arr[i]+1]--;
    for(int i=1;i<=n;i++) {
        hor[i]+=hor[i-1];
        if(hor[i]!=arr[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}