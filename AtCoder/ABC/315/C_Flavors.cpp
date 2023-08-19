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
    vector<int> mx1(n+1),mx2(n+1);
    for(int i=1;i<=n;i++) {
        int f,s;
        cin>>f>>s;
        if(s>mx1[f]) {
            mx2[f]=mx1[f];
            mx1[f]=s;
        }
        else mx2[f]=max(mx2[f],s);
    }

    int ans=0;
    multiset<int> st;
    for(int i=1;i<=n;i++) if(mx1[i]) st.insert(mx1[i]);
    if(st.size()>=2) {
        for(int i=1;i<=n;i++) {
            if(mx1[i]) {
                st.erase(st.find(mx1[i]));
                ans=max(ans,mx1[i]+*st.rbegin());
                st.insert(mx1[i]);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        if(mx2[i]) {
            ans=max(ans,mx1[i]+mx2[i]/2);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}