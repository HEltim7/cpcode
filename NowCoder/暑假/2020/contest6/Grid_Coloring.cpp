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
    int n,k;
    cin>>n>>k;
    if(n==1||k==1||2*n*(n+1)%k) {
        cout<<-1<<endl;
        return;
    }

    auto work=[&](int c) {
        bool flag=n%k==0;
        for(int i=1;i<=n+1;i++) {
            for(int j=1;j<=n;j++) {
                cout<<c+1<<" \n"[j==n];
                c=(c+1)%k;
            }
            if(flag) c=(c+1)%k;
        }
        return c;
    };
    work(work(0));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}