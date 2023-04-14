#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s>>s;

    char pre=' ';
    for(char x:s) {
        if(pre=='n'&&x=='a') cout<<'y';
        pre=x;
        cout<<x;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}