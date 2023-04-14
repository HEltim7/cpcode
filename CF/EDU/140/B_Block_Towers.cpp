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
    LL cur;
    cin>>n;
    cin>>cur;
    for(int i=2;i<=n;i++) cin>>arr[i];
    sort(arr+2,arr+n+1);
    for(int i=2;i<=n;i++) {
        if(arr[i]>cur) cur=(cur+arr[i]+1)/2;
    }
    cout<<cur<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}