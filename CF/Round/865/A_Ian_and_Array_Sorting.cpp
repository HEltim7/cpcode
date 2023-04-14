#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;

    LL odd=0,even=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(i&1) odd+=in;
        else even+=in;
    }

    if(n&1) {
        cout<<"YES"<<endl;
    }
    else {
        if(even>=odd) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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