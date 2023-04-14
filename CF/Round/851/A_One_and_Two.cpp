#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10;
int arr[N],pre[N],suf[N];

void solve() {
    int n;
    cin>>n;
    suf[n+1]=0;
    for(int i=1;i<=n;i++) cin>>arr[i],arr[i]=arr[i]==2;
    for(int i=1;i<=n;i++) pre[i]=arr[i]+pre[i-1];
    for(int i=n;i>=1;i--) suf[i]=arr[i]+suf[i+1];
    for(int i=1;i<n;i++) {
        if(pre[i]==suf[i+1]) {
            cout<<i<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}