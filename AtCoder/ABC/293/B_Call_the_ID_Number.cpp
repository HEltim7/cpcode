#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];
bool mark[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) {
        if(!mark[i]) mark[arr[i]]=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(!mark[i]) cnt++;
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++) if(!mark[i]) cout<<i<<' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}