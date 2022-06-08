#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;

void solve() {
    int n,k;
    cin>>n>>k;
    multiset<int> st;
    LL ans=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        ans+=in/k;
        st.insert(in%k);
    }
    while(st.size()) {
        int cur=*st.begin();
        st.erase(st.begin());
        int aim=k-cur;
        auto it=st.lower_bound(aim);
        if(it!=st.end()) {
            if(cur+*it>=k) ans++;
            st.erase(it);
        }
        else st.erase(st.begin());
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}