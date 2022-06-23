#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    multiset<int> st;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        st.insert(in);
    }
    int ans=0;
    while(st.size()) {
        int v=*st.begin();
        if(v==0) ans++;
        else if(st.count(-v)) ans+=2;
        else if(st.count(v)>=2) ans+=2;
        else ans++;
        st.erase(v),st.erase(-v);
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