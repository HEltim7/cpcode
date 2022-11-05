#include <iostream>
#include <fstream>
#include <testlib.h>
using namespace std;

#define endl '\n'
typedef long long LL;

void solve() {
    fstream fout("1.in",ios::out);
    int n=10,m=5,p=3;
    fout<<n<<' '<<m<<' '<<p<<endl;
    for(int i=2;i<=n;i++) fout<<rnd.next(1,10)<<" \n"[i==n];
    for(int i=1;i<=m;i++) fout<<rnd.next(1,n)<<' '<<rnd.next(1,n)<<endl;
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    registerGen(argc, argv, 1);
    solve();
    return 0;
}