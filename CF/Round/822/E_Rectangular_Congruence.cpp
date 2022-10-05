#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=550;
int arr[N][N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        for(int j=i;j<=n;j++) arr[i][j]=in+j-i;
        for(int j=i;j>=1;j--) arr[i][j]=in+i-j;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<arr[i][j]<<" \n"[j==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}