#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string in;
    cin>>in;
    int cnt=0;
    for(auto x:in) if(x=='N') cnt++;
    cout<<(cnt==1?"NO":"YES")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}