#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n,cnt1=0,cnt2=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr[in]++;
    }
    for(int i=1;i<N;i++) {
        if(arr[i]==1) cnt1++;
        else if(arr[i]>=3) cnt2++;
    }
    if(cnt1%2==0||cnt2) cout<<"YES";
    else cout<<"NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}