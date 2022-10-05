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
constexpr int A=26;
int pre[A],fa[A],sz[A];
bool mark[A];

int findfa(int x) {
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

void solve() {
    int n;
    string s;
    for(int i=0;i<A;i++) {
        pre[i]=-1;
        mark[i]=0;
        fa[i]=i;
        sz[i]=1;
    }
    
    cin>>n>>s;
    for(auto &x:s) {
        int c=x-'a';
        if(pre[c]==-1) {
            for(int i=0;i<A;i++) {
                if(mark[i]||(findfa(i)==findfa(c)&&sz[findfa(i)]<26))
                    continue;
                pre[c]=i;
                mark[i]=1;
                fa[i]=findfa(c);
                sz[findfa(c)]+=sz[i];
                break;
            }
        }
        debug(x,pre[c]);
        x=pre[c]+'a';
    }
    debug(pre);
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