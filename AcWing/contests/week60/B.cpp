#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> arr;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr.push_back(in);
    }
    sort(arr.begin(),arr.end());
    int sum=0;
    while(k--) {
        int pos=lower_bound(arr.begin(),arr.end(),sum+1)-arr.begin();
        if(pos==n) cout<<0<<endl;
        else {
            cout<<arr[pos]-sum<<endl;
            sum=arr[pos];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}