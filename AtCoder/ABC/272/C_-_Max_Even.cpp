#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> odd,even;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in&1) odd.push_back(in);
        else even.push_back(in);
    }    
    sort(odd.begin(),odd.end(),greater<int>());
    sort(even.begin(),even.end(),greater<int>());
    if(odd.size()<=1&&even.size()<=1) cout<<"-1";
    else {
        int ans=0;
        if(odd.size()>=2) ans=max(ans,odd[0]+odd[1]);
        if(even.size()>=2) ans=max(ans,even[0]+even[1]);
        cout<<ans;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}