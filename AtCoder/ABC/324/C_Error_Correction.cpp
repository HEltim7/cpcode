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
    int q;
    string t;
    cin>>q>>t;
    int n=t.size();

    vector<int> ans;
    for(int i=1;i<=q;i++) {
        string s;
        cin>>s;
        bool valid=false;
        if(s==t) valid=true;
        else if(s.size()==t.size()) {
            int dif=0;
            for(int i=0;i<n;i++) {
                dif+=s[i]!=t[i];
            }
            valid=dif==1;
        }
        else {
            auto check=[&](string s,string t) {
                while(s.size()&&s.back()==t.back()) s.pop_back(),t.pop_back();
                reverse(s.begin(),s.end());
                reverse(t.begin(),t.end());
                while(s.size()&&s.back()==t.back()) s.pop_back(),t.pop_back();
                return s.empty();
            };

            if(s.size()+1==t.size()) valid=check(s,t);
            else if(s.size()==t.size()+1) valid=check(t,s);
        }
        if(valid) ans.emplace_back(i);
    }

    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}