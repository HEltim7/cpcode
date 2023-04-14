#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n,x;
    cin>>n>>x;
    set<int> st;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        st.insert(arr[i]);
    }

    for(int i=1;i<=n;i++) {
        if(st.count(arr[i]-x)) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}