#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    string t;
    cin>>n>>t;
    vector<int> link(t.size()+10);
    auto kmp_build=[&](string t) {
        int n=t.size();
        t=" "+t;
        for(int i=2,j=0;i<=n;i++) {
            while(j&&t[i]!=t[j+1]) j=link[j];
            if(t[i]==t[j+1]) j++;
            link[i]=j; 
        }
    };
    kmp_build(t);

    auto check=[&](string s,string t) {
        int m=t.size();
        s=" "+s;
        t=" "+t;
        int cnt=0;
        for(int i=1,j=0;i<s.size();i++) {
            while(j&&s[i]!=t[j+1]) j=link[j];
            if(s[i]==t[j+1]) j++;
            if(j==m) {
                j=link[j];
                cnt++;
            }
        }
        debug(s,t,cnt);
        return cnt<=2;
    };

    if(check(t+string(n,'1')+t,t)) cout<<string(n,'1')<<endl;
    else if(check(t+string(n,'0')+t,t)) cout<<string(n,'0')<<endl;
    else cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}