#include <string>
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

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    auto flip=[](char &x) {
        if(x=='1') x='0';
        else x='1';
    };

    int ans=0;

    int cnt=0;
    for(auto x:s) if(x=='1') cnt++;
    if(cnt&1) cout<<-1<<endl;
    else {
        int i=find(s.begin(),s.end(),'1')-s.begin();
        int j=find(s.begin()+i+1,s.end(),'1')-s.begin();
        
        if(cnt==2&&i+1==j) {
            if(n==3) cout<<-1<<endl;
            else if(i-1<=1&&n-j<=1) cout<<3<<endl;
            else cout<<2<<endl;
        }
        else cout<<cnt/2<<endl;
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