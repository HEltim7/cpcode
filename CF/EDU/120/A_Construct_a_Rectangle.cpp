#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int arr[3];
    cin>>arr[0]>>arr[1]>>arr[2];
    sort(arr,arr+3);
    if(arr[2]==arr[0]+arr[1]) cout<<"YES"<<endl;
    else if(arr[0]==arr[1]&&arr[2]%2==0) cout<<"YES"<<endl;
    else if(arr[1]==arr[2]&&arr[0]%2==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}