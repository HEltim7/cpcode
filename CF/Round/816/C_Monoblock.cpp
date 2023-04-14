#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> seg;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++)
        if(seg.empty()||arr[seg.back().first]!=arr[i]) seg.emplace_back(i,i);
        else seg.back().second=i;

    LL ans=0;
    auto _cal=[](LL x) { return (x+1)*x/2; };
    auto cal=[&](int l,int r) { return _cal(n)-_cal(l-1)-_cal(n-r); };
    for(auto [l,r]:seg) ans+=cal(l,r);
    
    for(int i=1;i<=m;i++) {
        int x,idx;
        cin>>idx>>x;
        if(arr[idx]==x) continue;
        
        LL res=1LL*(idx-1)*(n-idx+1);
        if(arr[idx]==arr[idx-1]) ans+=res;
        else if(arr[idx-1]==x) ans-=res;
        
        res=1LL*idx*(n-idx);
        if(arr[idx]==arr[idx+1]) ans+=res;
        else if(arr[idx+1]==x) ans-=res;

        arr[idx]=x;
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}