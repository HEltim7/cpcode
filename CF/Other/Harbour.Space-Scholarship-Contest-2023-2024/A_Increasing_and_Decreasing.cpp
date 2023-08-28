#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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

void solve() {
    int x,y,n;
    cin>>x>>y>>n;
    vector<int> arr(n+1);
    arr[n]=y;
    for(int i=n-1,j=1;i>=1;i--,j++) arr[i]=arr[i+1]-j;
    if(arr[1]<x) cout<<-1<<endl;
    else {
        arr[1]=x;
        for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}