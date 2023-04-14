#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=4e5+10;
int arr[N];

void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=2*n;i++) arr[i]=i;
    if((a<=n)^(b<=n)) {
        reverse(arr+1,arr+1+2*n);
        b=2*n-b+1;
        swap(arr[a],arr[b]);
    }
    else swap(arr[a],arr[b]);
    for(int i=1;i<=2*n;i++) cout<<arr[i]<<" \n"[i==2*n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}