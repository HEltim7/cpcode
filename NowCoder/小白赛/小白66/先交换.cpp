#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &x:arr) cin>>x;
    if(arr.front()&1) cout<<0<<endl;
    else {
        for(int i=1;i<n;i++) 
            if(arr[i]%2&&arr[0]>arr[i]) {
                cout<<1<<endl;
                return;
            }
        cout<<-1<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}