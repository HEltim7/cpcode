#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int m;
LL ans;
string s;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<heltim7/debug>
#else
#define debug(...)
#endif

void dfs(int v,string cur) {
    if(cur.size()==m) {
        if(v==0) {
            // debug(cur);
            if(cur.find(s)!=cur.npos) ans++;
            // debug(cur.find(s));
        }
    }
    else {
        dfs(v+1,cur+'(');
        if(v>0) dfs(v-1,cur+')');
    }
}

void solve() {
    cin>>m;
    cin>>s;
    dfs(0,"");
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}
//(