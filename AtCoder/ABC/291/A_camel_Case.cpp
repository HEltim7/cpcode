#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) {
        if(s[i]>='A'&&s[i]<='Z') {
            cout<<i+1;
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