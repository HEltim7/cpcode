#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
int p[N],ans[N];

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    string s;
    cin>>s;
    vector<PII> like[2];
    for(int i=0;i<s.size();i++) {
        if(s[i]=='1') like[1].emplace_back(p[i],i);
        else like[0].emplace_back(p[i],i);
    }
    sort(like[0].begin(),like[0].end());
    sort(like[1].begin(),like[1].end());
    int idx=1;
    for(auto [a,b]:like[0]) ans[b]=idx++;
    for(auto [a,b]:like[1]) ans[b]=idx++;
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