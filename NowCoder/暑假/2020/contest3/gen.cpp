#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <testlib.h>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL = long long;

void solve() {
    int t=rnd.next(1,10);
    cout<<t<<endl;
    while(t--) {
        int n=rnd.next(int(2),int(10));
        int m=rnd.next(2,n);
        LL k=rnd.next(1LL,LL(m*n/2));
        cout<<n<<' '<<m<<' '<<k<<endl;
        for(int i=1;i<=n;i++) cout<<i<<" \n"[i==n];
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    rnd.setSeed(chrono::system_clock().now().time_since_epoch().count());
    solve();
    return 0;
}