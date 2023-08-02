#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <testlib.h>
#include <chrono>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int files=1;

void solve() {
    int n=rnd.next(2,300),m=rnd.next(2,300);
    cout<<n<<' '<<m<<endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout<<rnd.next(1,10)<<" \n"[j==m];
        }
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