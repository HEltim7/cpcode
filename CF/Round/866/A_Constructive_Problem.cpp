#include <set>
#include <vector>
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
int arr[N],bak[N];

void solve() {
    int n;
    cin>>n;
    set<int> st;
    for(int i=1;i<=n;i++) cin>>arr[i],bak[i]=arr[i];
    for(int i=1;i<=n;i++) st.insert(arr[i]);
    int mex=0;
    for(int i=0;;i++) {
        if(st.count(i)) mex++;
        else break;
    }
    if(mex==n) cout<<"No"<<endl;
    else {
        int pre=-1,suf=-1;
        for(int i=1;i<=n;i++) {
            if(bak[i]==mex+1) {
                if(pre==-1) pre=i;
                suf=i;
            }
        }
        debug(mex,pre,suf);
        if(pre==-1) {
            cout<<"Yes"<<endl;
            return;
        }
        for(int i=pre;i<=suf;i++) bak[i]=mex;
        set<int> st;
        for(int i=1;i<=n;i++) st.insert(bak[i]);

        int res=0;
        for(int i=0;;i++) {
            if(st.count(i)) res++;
            else break;
        }
        debug(res);
        if(res==mex+1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}