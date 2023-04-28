#include <algorithm>
#include <array>
#include <cassert>
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
    for(int i=0;i<=n;i++) {
        int tot=i*(i-1)/2+(n-i)*(n-i-1)/2;
        if(tot==k) {
            cout<<"YES"<<endl;
            for(int j=1;j<=i;j++) cout<<1<<' ';
            for(int j=1;j<=n-i;j++) cout<<-1<<' ';
            cout<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}