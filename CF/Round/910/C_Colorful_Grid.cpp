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
    int n,m,k;
    cin>>n>>m>>k;
    n--,m--;
    if((n+m)%2!=k%2||k<n+m) {
        cout<<"NO"<<endl;
        return;
    }

    bool ed=n&1;
    cout<<"YES"<<endl;
    for(int i=1;i<=n+1;i++) {
        for(int j=1;j<=m;j++) {
            if(i==n&&j==2) cout<<(ed?"B ":"R ");
            else {
                bool x=(j+ed)%2;
                cout<<(x?"R ":"B ");
            }
        }
        cout<<endl;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m+1;j++) {
            cout<<(i%2==1?"R ":"B ");
        }
        cout<<endl;
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