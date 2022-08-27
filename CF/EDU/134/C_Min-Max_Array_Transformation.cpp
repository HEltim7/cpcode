#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int a[N],b[N];
int pre[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) {
        int res=lower_bound(b+1,b+1+n,a[i])-b;
        cout<<b[res]-a[i]<<" \n"[i==n];
    }
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(a[i]<=b[i-1]);
    for(int i=1;i<=n;i++) {
        int l=i,r=n;
        while(l<r) {
            int mid=l+r+1>>1;
            if(pre[mid]-pre[i]==mid-i) l=mid;
            else r=mid-1;
        }
        cout<<b[r]-a[i]<<" \n"[i==n];
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