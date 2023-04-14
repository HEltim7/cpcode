#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int minn=1e9;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            minn=min(minn,gcd(arr[i],arr[j]));
    if(minn<=2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}