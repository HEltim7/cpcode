#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        arr.push_back(in);
    }
    sort(arr.begin(),arr.end());
    vector<PII> num;
    num.push_back(make_pair(*arr.begin(),1));
    for(int i=1;i<n;i++) {
        if(arr[i]==num.back().first) num.back().second++;
        else num.emplace_back(arr[i],1);
    }
    int ans=0;
    for(auto [a,b]:num) {
        ans+=min(2,b);
    }
    debug(ans);
    cout<<(ans+1)/2<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}