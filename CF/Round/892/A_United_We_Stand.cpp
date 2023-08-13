#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &x:arr) cin>>x;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++) {
        bool ok=true;
        int cnt=1;
        for(int j=0;j<n&&ok;j++) {
            if(i==j) continue;
            if(arr[i]==arr[j]) cnt++;
            else if(!(arr[i]%arr[j])) ok=false;
        }
        if(ok&&cnt<n) {
            cout<<cnt<<' '<<n-cnt<<endl;
            for(int j=1;j<=cnt;j++) cout<<arr[i]<<" \n"[j==cnt];
            for(int j=0;j<n;j++) if(arr[i]!=arr[j]) cout<<arr[j]<<' ';
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}