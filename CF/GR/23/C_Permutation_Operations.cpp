#include <set>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],ans[N];

void solve() {
    int n;
    cin>>n;
    set<int> st;
    for(int i=1;i<=n;i++) st.insert(i);
    memset(ans+1, 0, sizeof(int)*n);
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=2;i<=n;i++) {
        if(arr[i]<arr[i-1]) {
            int x=arr[i-1]-arr[i];
            int res=*st.lower_bound(x);
            st.erase(res);
            ans[res]=i;
        }
    }
    for(int i=1;i<=n;i++) if(ans[i]==0) ans[i]=1;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}