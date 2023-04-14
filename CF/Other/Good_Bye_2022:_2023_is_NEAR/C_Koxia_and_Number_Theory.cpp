#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    set<LL> st;
    vector<LL> arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i],st.insert(arr[i]);
    if(st.size()!=n) {
        cout<<"NO"<<endl;
        return;
    }
    for(int j=2;j<=n;j++) {
        vector<int> mark(j);
        for(int i=1;i<=n;i++) {
            int cur=arr[i]%j;
            mark[cur]++;
        }
        int cnt=0;
        for(int i=0;i<j;i++) cnt+=mark[i]>1;
        if(cnt==j) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}