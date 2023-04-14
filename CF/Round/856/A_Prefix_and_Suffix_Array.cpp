#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<string> arr;
    n=2*n-2;
    for(int i=1;i<=n;i++) {
        string in;
        cin>>in;
        arr.push_back(in);
    }
    sort(arr.begin(),arr.end(),[](string &s,string &t) {
        return s.size()<t.size();
    });

    bool res=1;
    for(int i=1;i<n;i+=2) {
        reverse(arr[i].begin(),arr[i].end());
        res&=arr[i-1]==arr[i];
    }
    cout<<(res?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}