#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<LL> arr;
    LL sum=0;
    for(int i=1;i<=n;i++){
        LL in;
        cin>>in;
        arr.push_back(in-(n-i));
        sum+=in;
    }
    LL t=k-1;
    LL tmp=(1+t)*t/2;
    sum-=tmp;
    sort(arr.begin(),arr.end(),greater<LL>());
    for(int i=0;i<k;i++) sum-=arr[i];
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}