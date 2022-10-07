#include <set>
#include <vector>
#include <cstring>
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
int cnt[1<<7];

void solve() {
    int n,k;
    cin>>n>>k;
    int tot=n/k;
    string s;
    cin>>s;

    memset(cnt, 0, sizeof(cnt));
    for(auto x:s) cnt[x]++;
    string res;
    for(int i=1;i<=k;i++) {
        bool flag=1;
        for(int c='a';c<=min(int('z'),'a'+tot-1);c++) {
            if(cnt[c]==0) {
                res.push_back(c);
                flag=0;
                break;
            }
            else cnt[c]--;
        }
        if(flag) res.push_back(char('a'+tot));
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}