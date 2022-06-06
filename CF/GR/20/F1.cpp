#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
PII arr[N];
int cnt[N],ans[N];

void solve() {
    int n,maxx=0;
    cin>>n;
    memset(cnt,0,sizeof (int)*(n+1));
    for(int i=0;i<n;i++) {
        cin>>arr[i].first;
        arr[i].second=i;
        maxx=max(maxx,++cnt[arr[i].first]);
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++) ans[arr[i].second]=arr[(i+maxx)%n].first;
    for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}