#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int arr[N];
int pre[N];

void solve() {
    int n;
    cin>>n;
    int x=0,s=0;
    for(int i=1;i<=n;i++) cin>>arr[i],s+=arr[i];
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+arr[i];
    for(int i=1;i<=n;i++) x=min(x,pre[i]);
    cout<<s-x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}