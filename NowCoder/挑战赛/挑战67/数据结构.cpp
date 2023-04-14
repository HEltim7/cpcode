#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
constexpr int N=3e5+10;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    map<pair<int,int>,int> mp;
    mp[{}]++;
    int x=0,y=0,z=0;

    LL ans=0;
    for(int i=1;i<=n;i++) {
        if(s[i]=='0') x++;
        else if(s[i]=='1') y++;
        else z++;
        ans+=mp[{y-x,z-x}];
        mp[{y-x,z-x}]++;
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