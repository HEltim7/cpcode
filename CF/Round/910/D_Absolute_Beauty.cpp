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
    LL sum=0;
    cin>>n;
    multiset<int> st;
    vector<int> a(n),b(n);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    for(int i=0;i<n;i++) {
        st.emplace(max(a[i],b[i]));
        sum+=abs(a[i]-b[i]);
    }

    LL ans=sum;
    for(int i=0;i<n;i++) {
        st.erase(st.find(max(a[i],b[i])));
        ans=max(ans,sum+2*(min(a[i],b[i])-*st.begin()));
        st.emplace(max(a[i],b[i]));
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}