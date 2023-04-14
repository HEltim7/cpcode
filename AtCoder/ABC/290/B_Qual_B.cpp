#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(auto &x:s) {
        if(x=='o') {
            if(m>0) m--;
            else x='x';
        }
    }
    cout<<s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}