#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    cout<<n<<endl;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        int j;
        for(j=1;j*2<arr[i];j*=2) ;
        cout<<i<<' '<<j*2-arr[i]<<endl;
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