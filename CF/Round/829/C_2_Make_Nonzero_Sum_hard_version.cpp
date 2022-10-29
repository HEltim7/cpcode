#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;

void solve() {
    int n;
    cin>>n;
    vector<int> arr,idx;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in) {
            arr.push_back(in);
            idx.push_back(i);
        }
    }
    if(arr.size()&1) {
        cout<<"-1"<<endl;
        return;
    }
    else if(arr.empty()) {
        cout<<1<<endl;
        cout<<1<<' '<<n<<endl;
        return;
    }
    idx.push_back(n);

    vector<pair<int,int>> ans;
    if(idx[0]>1) ans.emplace_back(1,idx[0]-1);
    for(int i=0;i<arr.size();i+=2) {
        if(arr[i]==arr[i+1]) {
            if(idx[i]+1==idx[i+1]) ans.emplace_back(idx[i],idx[i+1]);
            else ans.emplace_back(idx[i],idx[i+1]-2),ans.emplace_back(idx[i+1]-1,idx[i+1]);
        }
        else {
            ans.emplace_back(idx[i],idx[i]);
            if(idx[i]+1!=idx[i+1]) ans.emplace_back(idx[i]+1,idx[i+1]-1);
            ans.emplace_back(idx[i+1],idx[i+1]);
        }
        if(ans.back().second+1<idx[i+2]) ans.emplace_back(ans.back().second+1,idx[i+2]-1);
    }
    if(ans.back().second<n) ans.emplace_back(ans.back().second+1,n);
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}