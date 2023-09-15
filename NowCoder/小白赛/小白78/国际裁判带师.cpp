#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;
    int a=0,b=0,ans=0;
    for(char x:s) {
        if(x=='a') a++;
        else b++;

        auto get=[&](int x) {
            string t=to_string(x);
            if(t.size()==1) t.push_back('0');
            return (t[0]=='0')+(t[1]=='0');
        };
        ans+=get(a)+get(b);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}