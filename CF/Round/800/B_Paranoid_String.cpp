#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        arr[i]=in=='1';
    }
    LL ans=n;
    for(int i=1;i<n;i++) {
        if(arr[i]!=arr[i+1]) {
            ans+=i;
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