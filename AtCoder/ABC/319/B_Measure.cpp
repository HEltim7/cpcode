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
    for(int i=0;i<=n;i++) {
        for(int j=1;j<=10;j++) {
            if(j==10) {
                cout<<'-';
                break;
            }
            if(n%j) continue;
            if(i%(n/j)) continue;
            cout<<j;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}