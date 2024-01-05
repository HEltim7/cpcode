#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
    int ans=1;
    while(n--) {
        int in;
        cin>>in;
        if(in<0) ans*=-1;
        else if(in==0) ans=0;
    }
    if(ans<=0) cout<<0<<endl;
    else cout<<"1\n1 0\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}