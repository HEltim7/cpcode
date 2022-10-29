#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int pre=0;
    for(auto x:s) {
        if(x=='Q') pre++;
        else if(pre) pre--;
    }
    if(pre) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}