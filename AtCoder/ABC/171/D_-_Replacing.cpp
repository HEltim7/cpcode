#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    LL sum=0;
    map<int,int> mp;

    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        mp[in]++;
        sum+=in;
    }
    int q;
    cin>>q;
    while(q--) {
        int x,y;
        cin>>x>>y;
        auto it=mp.find(x);
        if(it!=mp.end()) {
            auto [a,b]=*it;
            sum+=1LL*(y-a)*b;
            mp.erase(it);
            mp[y]+=b;
        }
        cout<<sum<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}