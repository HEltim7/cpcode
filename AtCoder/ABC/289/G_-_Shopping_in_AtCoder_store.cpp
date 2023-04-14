#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=2e5+10;
int arr[N];
LL ans[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n,greater<>());

    vector<tuple<LD,LL,LL>> convex(1,{0,1,arr[1]});
    for(int i=2;i<=n;i++) {
        LD x;
        LL k=i,b=1LL*i*arr[i];
        while(convex.size()) {
            auto [xj,kj,bj]=convex.back();
            x=LD(bj-b)/(k-kj);
            if(x<=xj) convex.pop_back();
            else break;
        }
        convex.emplace_back(max(x,LD()),k,b);
    }

    vector<pair<int,int>> val(m);
    for(int i=0;i<m;i++) cin>>val[i].first,val[i].second=i+1;
    sort(val.begin(),val.end());
    for(int i=0,j=0;i<val.size();i++) {
        auto [v,id]=val[i];
        while(j+1<convex.size()&&get<0>(convex[j+1])<=v) j++;
        auto [x,k,b]=convex[j];
        ans[id]=b+k*v;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" \n"[i==m];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}