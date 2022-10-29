#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    int x,y;
    if(n&1) x=n,y=n/2;
    else x=n/2,y=n;
    for(int i=1;x;i+=2) arr[i]=x--;
    for(int i=2;y;i+=2) arr[i]=y--;
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