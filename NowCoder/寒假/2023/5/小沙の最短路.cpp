#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    int mid=(n+1)/2;
    cout<<mid<<' '<<mid<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(i>=mid+1&&j<=mid) {
                int layer=max(abs(i-(mid+1)),abs(j-mid));
                cout<<(layer*2+1)%3;
            }
            else {
                int layer=max(abs(i-mid),abs(j-mid));
                cout<<(layer*2)%3;
            }
            cout<<" \n"[j==n];
        }
    cout<<n*n-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}