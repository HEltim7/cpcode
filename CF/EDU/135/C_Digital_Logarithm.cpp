#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    multiset<int,greater<>> st1,st2;
    for(int i=1,in;i<=n;i++) cin>>in,st1.insert(in);
    for(int i=1,in;i<=n;i++) cin>>in,st2.insert(in);
    int ans=0;
    while(st1.size()&&st2.size()) {
        int x=*st1.begin();
        int y=*st2.begin();
        if(x==y) st1.erase(st1.begin()),st2.erase(st2.begin());
        else if(x<y) st2.erase(st2.begin()),st2.insert(log10(y)+1),ans++;
        else st1.erase(st1.begin()),st1.insert(log10(x)+1),ans++;
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