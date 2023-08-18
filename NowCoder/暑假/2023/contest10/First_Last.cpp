#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;

void solve() {
    int n,m;
    cin>>n>>m;
    LD ans=1;
    for(int i=1;i<=m;i++) ans*=LD(min(n,2))/n;
    cout<<fixed<<setprecision(15)<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}