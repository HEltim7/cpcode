#include <algorithm>
#include <array>
#include <cassert>
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
    string s;
    cin>>s;
    int idx=-1;
    for(int i=0;i<s.size();i++) {
        if(s[i]!='?') {
            idx=i;
            break;
        }
    }
    if(idx==-1) {
        cout<<string(s.size(),'0')<<endl;
        return;
    }

    char cur=s[idx];
    for(int i=idx-1;i>=0;i--) {
        if(s[i]=='?') s[i]=cur;
        else cur=s[i];
    }

    cur=s[idx];
    for(int i=idx+1;i<s.size();i++) {
        if(s[i]=='?') s[i]=cur;
        else cur=s[i];
    }
    cout<<s<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}