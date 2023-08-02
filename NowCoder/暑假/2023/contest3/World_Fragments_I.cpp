#include <algorithm>
#include <array>
#include <bitset>
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
    bitset<62> x,y;
    cin>>x>>y;
    LL a=x.to_ullong();
    LL b=y.to_ullong();
    if(a==0&&b) cout<<-1<<endl;
    else cout<<abs(a-b)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}