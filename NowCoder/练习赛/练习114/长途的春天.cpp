#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        cnt[in]++;
    }
    
    vector<int> len(10);
    for(int i=1;i<=n;i++) {
        vector<int> ne(10);
        for(int j=1;j<=4;j++) {
            if(cnt[i]<len[j]) {
                cout<<"NO"<<endl;
                return;
            }
            else ne[j+1]=len[j],cnt[i]-=len[j];
        }
        int t=min(len[5],cnt[i]);
        ne[5]+=t;
        ne[1]+=cnt[i]-t;
        len=ne;
    }
    for(int i=1;i<=4;i++) if(len[i]) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}