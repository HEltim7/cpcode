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
    int fs,fe;
    bool valid=true;
    for(int i=1;i<=n;i++) {
        int s,e;
        cin>>s>>e;
        if(i==1) fs=s,fe=e;
        else {
            if(s>=fs&&e>=fe) {
                valid=false;
            }
        }
    }
    if(valid) cout<<fs<<endl;
    else cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}