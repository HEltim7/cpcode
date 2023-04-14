#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int link[N],cnt[N];
string t;

void kmp_build(int n) {
    for(int i=2,j=0;i<=n;i++) {
        while(j&&t[i]!=t[j+1]) j=link[j];
        if(t[i]==t[j+1]) j++;
        link[i]=j;
        cnt[j]++;
    }
}

void solve() {
    cin>>t;
    int n=t.size();
    t=" "+t;
    kmp_build(n);

    for(int j=n;j>=1;j--) if(cnt[j]) cnt[link[j]]+=cnt[j],cnt[j]++;

    vector<pair<int,int>> ans(1,{n,1});
    for(int j=link[n];j>=1;j=link[j]) ans.emplace_back(j,cnt[j]);
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}