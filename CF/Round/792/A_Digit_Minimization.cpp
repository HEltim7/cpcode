#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    string in;
    cin>>in;
    string bak=in;
    sort(bak.begin(),bak.end());
    if(in.size()==2&&in.front()==bak.front()) cout<<bak[1]<<endl;
    else cout<<bak[0]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}