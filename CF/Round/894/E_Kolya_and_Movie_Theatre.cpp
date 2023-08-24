#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <limits>
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
    int n,m,d;
    cin>>n>>m>>d;
    LL sum=0,ans=0;
    multiset<int> st;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in>0) {
            sum+=in;
            st.emplace(in);
            if(st.size()>m) sum-=*st.begin(),st.erase(st.begin());
        }
        ans=max(ans,sum-1LL*i*d);
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