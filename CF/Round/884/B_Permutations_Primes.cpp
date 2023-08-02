#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    if(n<=2) {
        for(int i=1;i<=n;i++) cout<<i<<" \n"[i==n];
    }
    else if(n==3) cout<<"3 1 2"<<endl;
    else if(n==4) cout<<"3 4 1 2"<<endl;
    else {
        int mid=(n+1)/2;
        arr[mid]=1;
        arr[mid+1]=2;
        arr[1]=3,arr[2]=4;
        arr[n]=5;
        
        int idx=5;
        for(int i=3;i<mid;i++) arr[i]=++idx;
        for(int i=mid+2;i<n;i++) arr[i]=++idx;
        for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
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