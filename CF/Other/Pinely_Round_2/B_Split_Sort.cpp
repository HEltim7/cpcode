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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    set<int> st;
    for(int i=1;i<=n;i++) {
        if(st.size()&&st.find(arr[i]-1)!=st.end()) {
            st.erase(arr[i]-1);
            st.insert(arr[i]);
        }
        else st.insert(arr[i]);
    }
    int ans=st.size();
    cout<<ans-1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}