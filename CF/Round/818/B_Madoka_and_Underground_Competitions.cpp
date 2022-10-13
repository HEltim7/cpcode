#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=550;
char grid[N][N];

void solve() {
    int n,k,r,c;
    cin>>n>>k>>r>>c;
    r--,c--;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) grid[i][j]='.';
    for(int i=0;i<n;i++)
        for(int j=0;j<n/k;j++) {
            grid[(r+i)%n][(c+i+j*k)%n]='X';
        }
    for(int i=0;i<n;i++,cout<<endl) for(int j=0;j<n;j++) cout<<grid[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}