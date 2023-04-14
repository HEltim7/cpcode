#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    auto check=[&](int idx) {
        return s[idx]=='.'&&(idx-1<0||s[idx-1]!='L')&&(idx+1>n-1||s[idx+1]!='L');
    };

    for(int i=0;i<n;i++) {
        if(check(i)) s[i]='C';
    }
    cout<<s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}