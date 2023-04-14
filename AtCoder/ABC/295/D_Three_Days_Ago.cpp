#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;
    map<int,int> mp;
    mp[0]++;
    LL ans=0;
    int cur=0;
    for(auto x:s) {
        int c=x-'0';
        cur^=1<<c;
        ans+=mp[cur];
        mp[cur]++;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}