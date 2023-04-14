#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    if(arr[1]!=1) {
        cout<<"NO"<<endl;
        return;
    }

    LL sum=1;
    for(int i=2;i<=n;i++) {
        if(arr[i]>sum) {
            cout<<"NO"<<endl;
            return;
        }
        else sum+=arr[i];
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