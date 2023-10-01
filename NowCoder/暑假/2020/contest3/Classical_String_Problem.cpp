#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;
    int q;
    cin>>q;

    int n=s.size();
    int idx=0;
    while(q--) {
        char op;
        int x;
        cin>>op>>x;
        if(op=='M') {
            idx=(idx+x+n)%n;
        }
        else {
            int pos=(idx+x-1)%n;
            cout<<s[pos]<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}