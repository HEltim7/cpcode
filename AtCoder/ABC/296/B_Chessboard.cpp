#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    for(int i=8;i>=1;i--)
        for(int j=1;j<=8;j++) {
            char in;
            cin>>in;
            if(in=='*') {
                cout<<char(j+'a'-1)<<i;
                return;
            }
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}