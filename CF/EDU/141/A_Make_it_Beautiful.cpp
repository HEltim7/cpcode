#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int arr[N],tmp[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tmp[i];
    sort(tmp+1,tmp+1+n,greater<>());
    for(int i=2;i<=n;i++) arr[i]=tmp[i-1];
    arr[1]=tmp[n];
    
    for(int i=2,sum=arr[1];i<=n;i++) {
        if(arr[i]==sum) {
            cout<<"NO"<<endl;
            return;
        }
        sum+=arr[i];
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}