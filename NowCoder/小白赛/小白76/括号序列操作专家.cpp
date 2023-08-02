#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;

    int pre=0;
    LL ans=0;
    for(int i=1;i<=n;i++) {
        char in;
        cin>>in;
        if(in=='(') pre++;
        else pre--;
        if(pre<0) ans+=abs(pre-1)/2;
    }

    cout<<(pre==0?ans:-1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}