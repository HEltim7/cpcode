#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    int l=(n+1)/2,r=n/2+1;
    
    int i=find(arr,arr+1+n,l)-arr;
    int j=find(arr,arr+1+n,r)-arr;
    if(i>j) cout<<n/2<<endl;
    else {
        while(i>1&&j<n) {
            while(i>1&&arr[--i]!=l-1);
            while(j<n&&arr[++j]!=r+1);
            if(arr[i]==l-1&&arr[j]==r+1) l--,r++;
            else break;
        }
        cout<<(n-(r-l+1))/2<<endl;
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