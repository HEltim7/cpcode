#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=10,M=2e5+10;
map<int,vector<string>> dp;


void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    
    int l=max(n/k-2,1);
    int r=min(n/k+2,n);

    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}