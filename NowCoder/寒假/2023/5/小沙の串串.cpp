#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int A=26,B='a';
set<int> st[A];

void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    if(k+1>=n) {
        sort(s.begin(),s.end(),greater<>());
        cout<<s;
    }
    else {
        for(int i=0;i<n;i++) st[s[i]-B].insert(i);
        string ans,suf;
        int maxx=0,idx=0;
        for(int i=0;i<n;) {
            bool flag=0;
            for(int j=A-1;j>=maxx;j--) {
                auto it=st[j].lower_bound(i);
                if(it!=st[j].end()&&*it-i<=k) {
                    ans.push_back(j+B);
                    k-=*it-i;
                    for(int z=i;z<*it;z++) suf.push_back(s[z]),maxx=max(maxx,s[z]-B);
                    i=*it+1;
                    flag=1;
                    break;
                }
            }
            idx=i;
            if(!flag) break;
        }

        for(int i=idx;i<n&&k<(n-i);idx=i) {
            for(int j=A-1;j>=0;j--) {
                auto it=st[j].lower_bound(i);
                if(it!=st[j].end()&&*it-i<=k) {
                    ans.push_back(j+B);
                    k-=*it-i;
                    for(int z=i;z<*it;z++) suf.push_back(s[z]);
                    i=*it+1;
                    break;
                }
            }
        }
        for(int i=idx;i<n;i++) suf.push_back(s[i]);

        sort(suf.begin(),suf.end(),greater<>());
        ans+=suf;
        cout<<ans;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}