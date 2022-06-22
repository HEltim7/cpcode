#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int len;
    string t;
    cin>>len>>t;
    vector<int> ans(len,0),num(len,0);
    for(int i=0;i<len;i++) num[i]=t[i]-'0';
    if(num.front()==9) {
        for(int i=len-1;i>=0;i--) {
            if(num[i]>=10) ans[i]=0;
            else ans[i]=10-num[i];
            if(num[i]+ans[i]>=10&&i) num[i-1]++;
        }
        debug(num,ans);
        for(int i=0;i<len;i++) ans[i]++;
        for(int i=len-1;i>=0;i--) {
            if(ans[i]>=10) ans[i]-=10,ans[i-1]++;
        }
    }
    else {
        for(int i=0;i<len;i++) ans[i]=9-num[i];
    }
    for(int i=0;i<len;i++) cout<<ans[i];
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