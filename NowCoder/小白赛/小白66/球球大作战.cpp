#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e5+10;
int arr[N],ans[N];
int suf[N];

void solve() {
    int n;
    cin>>n;
    
    vector<pair<int,int>> v;
    for(int i=1;i<=n;i++) cin>>arr[i],v.emplace_back(arr[i],i);
    sort(v.begin(),v.end());
    
    suf[n-1]=v.back().first;
    for(int i=n-2;i>=0;i--) suf[i]=(suf[i+1]+v[i].first)/2;
    for(int i=0;i<n;i++) {
        auto [x,id]=v[i];
        int val=suf[i+1];
        for(int j=i-1;j>=0&&val>x;j--) val=(val+v[j].first)/2;
        if(x>=val) ans[id]=1;
        else ans[id]=0;
    }
    for(int i=1;i<=n;i++) cout<<ans[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}