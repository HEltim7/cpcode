#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10,INF=1e9;
int arr[N],cnt[N],maxx[N],ans[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    set<int> st;
    st.insert(0);
    cnt[n+1]=0;
    maxx[n+1]=0;
    for(int i=n;i>=1;i--) {
        cnt[i]=maxx[i]=0;
        if(i+arr[i]+1<=n+1) cnt[i]=cnt[i+arr[i]+1]+1;
        else cnt[i]=INF;
        maxx[i]=*st.rbegin()+1;
        if(i+arr[i]+1<=n+1) maxx[i]=max(maxx[i],maxx[i+arr[i]+1]+1);
        if(cnt[i]<INF) st.insert(cnt[i]);
    }

    for(int i=n;i>=2;i--) {
        if(arr[i-1]==cnt[i]) ans[i-1]=0;
        else if(cnt[i]<INF) ans[i-1]=1;
        else if(maxx[i]>=arr[i-1]) ans[i-1]=1;
        else ans[i-1]=2;
    }
    for(int i=1;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}