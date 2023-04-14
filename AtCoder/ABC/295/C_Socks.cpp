#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;


void solve() {
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> arr(n);
    for(int &x:arr) cin>>x,mp[x]++;
    int ans=0;
    for(auto [x,y]:mp) {
        ans+=y/2;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}