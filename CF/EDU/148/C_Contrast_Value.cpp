#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=3e5+10;
bool mark[N];

void solve() {
    int n;
    cin>>n;
    vector<int> arr(1,-1);
    for(int i=1;i<=n;i++) mark[i]=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in!=arr.back()) arr.push_back(in);
    }

    n=arr.size()-1;
    mark[1]=mark[n]=1;
    for(int i=2;i<n;i++) {
        bool x=arr[i]>arr[i-1];
        bool y=arr[i]>arr[i+1];
        if(x&&y||!x&&!y) mark[i]=1;
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans+=mark[i];
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