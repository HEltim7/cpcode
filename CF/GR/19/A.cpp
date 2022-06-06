#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr.push_back(in);
    }
    if(is_sorted(arr.begin(),arr.end())) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}