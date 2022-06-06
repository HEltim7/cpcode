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
    vector<int> seg;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]==arr[i-1]) seg.back()++;
        else seg.push_back(1);
    }
    for(auto x:seg) if(x<=1) {
        cout<<"-1\n";
        return;
    }
    int idx=1;
    for(auto x:seg) {
        for(int i=idx+1;i<idx+x;i++) cout<<i<<' ';
        cout<<idx<<' ';
        idx+=x;
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}