#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N];

void solve() {
    int n;
    cin>>n;
    arr[n]=n,arr[n-1]=n-1;
    if(n&1) {
        arr[1]=1;
        for(int i=2;i<=n-2;i++) arr[i]=n-2-i+2;
    }
    else for(int i=1;i<=n-2;i++) arr[i]=n-2-i+1;
    for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}