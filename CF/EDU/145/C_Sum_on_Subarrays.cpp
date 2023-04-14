#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=100;
int arr[N];

void solve() {
    int n,k;
    cin>>n>>k;
    bool flag=1;
    for(int i=1,len=1;i<=n;i++) {
        int cur=i*(i+1)/2;
        if(cur<=k) {
            arr[i]=2;
        }
        else if(flag) {
            int t=cur-k-1;
            arr[i]=t*-2-1;
            flag=0;
        }
        else arr[i]=-1000;
    }
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