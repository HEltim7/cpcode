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
    int n,k,x;
    cin>>n>>k>>x;
    if(k>min(n,x+1)) cout<<-1<<endl;
    else {
        int ans=0;
        for(int i=0;i<k;i++) ans+=i,n--;
        if(k==x) ans+=(x-1)*n;
        else ans+=x*n;
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}