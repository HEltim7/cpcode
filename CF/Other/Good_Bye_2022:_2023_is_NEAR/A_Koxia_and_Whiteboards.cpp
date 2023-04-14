#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N];

void solve() {
    int n,m;
    cin>>n>>m;
    multiset<int> st;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        st.insert(in);
    }
    for(int i=1;i<=m;i++) {
        int in;
        cin>>in;
        st.erase(st.begin());
        st.insert(in);
    }
    LL sum=0;
    for(auto x:st) sum+=x;
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}