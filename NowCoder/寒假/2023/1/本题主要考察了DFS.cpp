#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=22;
string pta[N*N];

void solve() {
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<n*n;i++) {
        cin>>pta[i];
        for(auto x:pta[i]) if(x=='1') cnt--; else if(x=='2') cnt++;
        pta[i]=" "+pta[i];
    }
    // assert(abs(cnt)<=4);
    cout<<10-cnt<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}