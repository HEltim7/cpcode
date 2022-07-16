#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10;
int arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=2*n;i++) cin>>arr[i];
    sort(arr+1,arr+1+2*n);
    for(int i=1;i<=n;i++) {
        if(arr[i+n]-arr[i]<k) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}