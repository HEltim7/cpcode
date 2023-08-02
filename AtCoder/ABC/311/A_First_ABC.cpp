#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    int n;
    string s;
    cin>>n>>s;
    int a=0,b=0,c=0;
    for(int j=0;j<n;j++) {
        if(s[j]=='A') a++;
        if(s[j]=='B') b++;
        if(s[j]=='C') c++;
        if(a&&b&&c) {
            cout<<j+1<<endl;
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