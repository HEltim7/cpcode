#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10,INF=0x3f3f3f3f;
PII arr[N];

void solve() {
    int n,maxx=0,L=INF,R=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first;
    for(int i=1;i<=n;i++) cin>>arr[i].second;
    for(int i=1;i<=n;i++) maxx=max(maxx,arr[i].second);
    for(int i=1;i<=n;i++) 
        if(arr[i].second==maxx) 
            L=min(L,arr[i].first),R=max(R,arr[i].first);
    int l=INF,r=0;
    for(int i=1;i<=n;i++) {
        auto [p,t]=arr[i];
        if(p<L) p=min(L,p+maxx-t);
        else if(p>R) p=max(R,p-maxx+t);
        l=min(l,p);
        r=max(r,p);
    }
    cout<<fixed<<setprecision(7)<<(double(l)+r)/2<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}