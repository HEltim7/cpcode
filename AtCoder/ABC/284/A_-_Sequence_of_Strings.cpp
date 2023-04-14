#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<string> v;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }
    reverse(v.begin(),v.end());
    for(auto x:v) cout<<x<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}