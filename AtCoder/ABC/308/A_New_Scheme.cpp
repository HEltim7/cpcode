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
int arr[10];

void solve() {
    int n=8;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=2;i<=n;i++) {
        if(arr[i]<arr[i-1]) {
            cout<<"No"<<endl;
            return;
        }
    }

    for(int i=1;i<=n;i++) {
        if(arr[i]<100||arr[i]>675||arr[i]%25) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}