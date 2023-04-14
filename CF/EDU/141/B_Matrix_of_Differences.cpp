#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N][N];

void solve() {
    int n;
    cin>>n;
    int L=1,R=n*n;
    for(int i=2;i<=n*2;i++) {
        for(int r=1;r<=n;r++) {
            int c=i-r;
            if(c>=1&&c<=n) {
                if(i&1) arr[r][c]=R--;
                else arr[r][c]=L++;
            }
        }
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<arr[i][j]<<" \n"[j==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}