#include <map>
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
    for(int i=1,j=n,l=1,r=n;i<j;) {
        if(arr[i]==l) i++,l++;
        if(arr[j]==l) j--,l++;
        if(arr[i]==r) i++,r--;
        if(arr[j]==r) j--,r--;

        if(i<j&&min(arr[i],arr[j])>l&&max(arr[i],arr[j])<r) {
            cout<<i<<' '<<j<<endl;
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