#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s>>s;
    for(int i=1;i<s.size();i++) {
        if(s[i]==s[i-1]) {
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}