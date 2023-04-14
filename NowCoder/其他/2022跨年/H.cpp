#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=810;
int arr[N][N];

void solve() {
    int n;
    LL sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>arr[i][j],sum+=arr[i][j];
    if(n&1) cout<<sum;
    else {
        int minn=1e9;
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++)
                if((i+j)&1)
                    minn=min(minn,arr[i][j]);
        cout<<sum-minn;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}