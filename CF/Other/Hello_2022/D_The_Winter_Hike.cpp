#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=550;
LL grid[N][N];

void solve() {
    LL ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++)
        for(int j=1;j<=2*n;j++) {
            cin>>grid[i][j];
            if(i>n&&j>n) ans+=grid[i][j];
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