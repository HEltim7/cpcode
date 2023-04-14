#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];
LL pre[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];

    int ans=0;

    for(int i=1;i<=m;i++) {
        pre[i]=pre[i-1]+arr[i];
    }
    multiset<int,greater<>> stl;
    stl.insert(arr[m]);
    for(int i=m-1;i>=1;i--) {
        if(pre[i]<pre[m]) {
            pre[m]-=2**stl.begin();
            stl.erase(stl.begin());
            ans++;
        }
        stl.insert(arr[i]);
    }

    for(int i=m+1;i<=n;i++) {
        pre[i]=pre[i-1]+arr[i];
    }
    multiset<int,less<>> str;
    for(int i=m+1;i<=n;i++) {
        str.insert(arr[i]);
        if(pre[i]<pre[m]) {
            pre[m]+=2**str.begin();
            str.erase(str.begin());
            ans++;
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}