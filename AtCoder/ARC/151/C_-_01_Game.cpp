#include <vector>
#include <cassert>
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
constexpr int N=2e5+10;
LL pos[N];
bool val[N];

void solve() {
    LL n,m;
    cin>>n>>m;
    if(m==0) {
        if(n&1) cout<<"Takahashi"<<endl;
        else cout<<"Aoki"<<endl;
        return;
    }

    bool ans=0;
    for(int i=1;i<=m;i++) {
        cin>>pos[i]>>val[i];
        if(i>1) {
            int len=pos[i]-pos[i-1]-1;
            if(val[i]^val[i-1]) {
                if(len%2) len--;
                ans^=len&1;
            }
            else {
                if(len%2==0) len--;
                ans^=len&1;
            }
        }
    }
    
    int cnt=0;
    if(pos[1]-1==1) ans^=1;
    else if(pos[1]-1>1) cnt++;
    if(n-pos[m]==1) ans^=1;
    else if(n-pos[m]>1) cnt++;

    if(cnt==1) ans=1;
    else if(cnt==2) ans=0;
    
    if(ans) cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}