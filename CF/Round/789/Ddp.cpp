#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
deque<int> dq[N];
int n,m;

#define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

int count() {
    int res=0;
    for(int i=1;i<=n;i++) {
        if(dq[i].empty()) break;
        int cur=0;
        for(auto x:dq[i]) cur=max(cur,x);
        res+=cur;
    }
    for(int i=1;i<=m;i++) {
        int cur=0;
        for(int j=1;j<=n;j++) {
            if(dq[j].size()<i) break;
            cur=max(cur,dq[j][i-1]);
        }
        res+=cur;
    }
    return res;
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) dq[i].clear();
    string s;
    cin>>s;
    for(auto x:s) {
        int k=x=='1';
        dq[1].push_front(k);
        for(int i=1;i<=n;i++) {
            if(dq[i].size()>m) {
                int t=dq[i].back();
                dq[i].pop_back();
                dq[i+1].push_front(t);
            }
        }
        cout<<count()<<' ';
    }
    debug();
    for(int i=1;i<=n;i++) 
        if(dq[i].size()) debug(dq[i]);
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}