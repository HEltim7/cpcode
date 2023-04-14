#include <map>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    map<int,int> mp;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i],mp[arr[i]]++;
    for(auto it=mp.begin();it!=mp.end();) {
        if(it->second==1) {
            ans++;
            it=mp.erase(it);
        }
        else it++;
    }
    cout<<ans<<endl;
    
    for(int i=2;i<=n;i++) {
        for(auto it=mp.begin();it!=mp.end();) {
            if(it->second>=3) {
                ans++;
                it->second--;
                it++;
            }
            else if(it->second==2) {
                ans+=2;
                it=mp.erase(it);
            }
            else assert(0);
        }
        cout<<ans<<endl;
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