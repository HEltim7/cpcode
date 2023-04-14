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
    for(int i=0;i<n;i++) {
        cin>>arr[i][i];
        for(int k=1;k<n;k++)
            arr[i][(i+k)%n]=(arr[i][i]+k*(i+1))%n;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" \n"[j+1==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}