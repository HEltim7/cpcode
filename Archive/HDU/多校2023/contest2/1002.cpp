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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
bool arr[N];
int ri[N];

void solve() {
    int n;
    LL k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        arr[i]=in=='1';
    }

    if(n==1) {
        if(k&1) arr[1]^=1;
        cout<<arr[1]<<endl;
        return;
    }

    for(int i=n,last=n+1;i>=1;i--) {
        if(arr[i]) last=i;
        ri[i]=last;
    }

    int flip=0;
    for(int i=1;i<=n&&k;) {
        if(arr[i]) i++;
        else {
            flip++;
            k--;
            for(int j=i;j<ri[i];j++) arr[j]=1;
            i=ri[i];
        }
    }

    if(k==1&&!flip) arr[n]^=1;
    for(int i=1;i<=n;i++) cout<<arr[i];
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}