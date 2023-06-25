#include <algorithm>
#include <array>
#include <cassert>
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
    int n,d;
    cin>>n>>d;
    LL maxx=1LL*n*(n-1)/2;
    if(1LL*n*d>maxx) {
        cout<<"No"<<endl;
        return;
    }

    set<pair<int,int>> st;
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}