#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=20;
int arr[N];

void solve() {
    int n,m;
    cin>>n>>m;
    int ans=0,aim=0;
    for(int i=1;i<=n;i++) aim|=1<<i;
    for(int i=1;i<=m;i++) {
        int c;
        cin>>c;
        for(int j=1;j<=c;j++) {
            int in;
            cin>>in;
            arr[i]|=1<<in;
        }
    }

    for(int i=1;i<1<<m;i++) {
        int cur=0;
        for(int j=0;j<m;j++) {
            if(i>>j&1) {
                cur|=arr[j+1];
            }
        }
        ans+=cur==aim;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}