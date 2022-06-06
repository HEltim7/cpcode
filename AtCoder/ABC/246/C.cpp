#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k,x;
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<int> left;
    for(int i=1;i<=n;i++){
        int t=arr[i]/x;
        left.push_back(arr[i]-min(k,t)*x);
        k-=min(k,t);
    }
    LL ans=0;
    sort(left.begin(),left.end(),greater<int>());
    for(auto t:left){
        if(k) k--;
        else ans+=t;
    }
    cout<<ans;
    return 0;
}