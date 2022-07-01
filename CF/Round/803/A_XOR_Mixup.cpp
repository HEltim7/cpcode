#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int arr[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n;
    cin>>n;
    int x=0;
    for(int i=1;i<=n;i++) cin>>arr[i],x^=arr[i];
    for(int i=1;i<=n;i++) {
        int t=x^arr[i];
        debug(x,t,arr[i]);
        if(t==arr[i]) {
            cout<<arr[i]<<endl;
            return;
        }
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