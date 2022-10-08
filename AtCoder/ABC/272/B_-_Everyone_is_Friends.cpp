#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=1e2+10;
bool mark[N][N];

void solve() {
    int n,m;
    cin>>n>>m;
    while(m--) {
        int k;
        cin>>k;
        vector<int> arr(k);
        for(int i=0;i<k;i++) cin>>arr[i];
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                mark[arr[i]][arr[j]]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            if(!mark[i][j]) {
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