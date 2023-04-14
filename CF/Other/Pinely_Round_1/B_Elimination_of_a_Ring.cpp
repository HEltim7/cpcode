#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    bool flag=0;
    for(int i=0;i<n;i++) if(arr[(i-1+n)%n]!=arr[(i+1)%n]) flag=1;
    if(flag||n<=2) cout<<n<<endl;
    else cout<<n/2+1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}