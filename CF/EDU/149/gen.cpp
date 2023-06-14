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
        fstream fout(to_string(z)+".in",ios::out);
        fout<<19<<endl;
        for(int i=1;i<=1<<19;i++) fout<<-1<<' ';
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    solve();
    return 0;
}