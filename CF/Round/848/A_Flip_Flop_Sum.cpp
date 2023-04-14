#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    int ans=0;
    vector<int> arr(n);
    for(auto &x:arr) cin>>x,ans+=x;

    bool add=0,equ=0;
    for(int i=1;i<arr.size();i++) 
        if(arr[i-1]==-1&&arr[i]==-1) add=1;
        else if(arr[i-1]!=arr[i]) equ=1;
    if(add) ans+=4;
    else if(!equ) ans-=4;
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