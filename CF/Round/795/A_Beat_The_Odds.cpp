#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    int odd=0,even=0;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]&1) odd++;
        else even++;
    }
    cout<<min(odd,even)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}