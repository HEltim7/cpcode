#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <testlib.h>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int files=1;

void solve() {
    for(int z=1;z<=files;z++) {
        fstream fout("data/"+to_string(z)+".in",ios::out);
        int n=1e6,m=1e6,k=1e9;
        fout<<1<<endl;
        fout<<n<<' '<<m<<' '<<k<<endl;
        for(int i=1;i<=n;i++) fout<<rnd.next(1,m)<<" \n"[i==n];
        for(int i=1;i<=m;i++) fout<<rnd.next(1,k)<<" \n"[i==m];
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    solve();
    return 0;
}