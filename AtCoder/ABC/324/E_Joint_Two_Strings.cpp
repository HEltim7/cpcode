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

#define endl '\n'
using LL=long long;

void solve() {
    int q;
    string s;
    cin>>q>>s;
    int n=s.size();

    vector<int> pre(q),suf(q),cnt(n+10);
    for(int i=0;i<q;i++) {
        string t;
        cin>>t;
        int idx=-1;
        for(int j=0;j<t.size()&&idx<n;j++) {
            if(s[idx+1]==t[j]) idx++;
        }
        pre[i]=idx;

        idx=n;
        reverse(t.begin(),t.end());
        for(int j=0;j<t.size()&&idx>0;j++) {
            if(s[idx-1]==t[j]) idx--;
        }
        suf[i]=idx;
        cnt[suf[i]]++;
    }
    partial_sum(cnt.begin(),cnt.end(),cnt.begin());

    LL ans=0;
    for(int i=0;i<q;i++) {
        ans+=cnt[pre[i]+1];
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}