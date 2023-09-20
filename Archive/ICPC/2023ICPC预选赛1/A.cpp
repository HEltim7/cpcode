#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 10;

vector<string> cancel_decu(vector<string>& a) {
    set<string> st;
    vector<string> b;
    for(string& s:a) {
        if(st.insert(s).second) {
            b.push_back(s);
        }
    }
    return b;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    vector<string> b(m);
    for(auto& x:a) cin>>x;
    for(auto& x:b) cin>>x;
    a=cancel_decu(a);
    b=cancel_decu(b);

    int up=min(a.size(), b.size());
    int i=0;
    vector<string> c;
    while(i<up) {
        c.push_back(a[i]);
        c.push_back(b[i++]);
    }
    while(i<a.size()) {
        c.push_back(a[i++]);
    }
    while(i<b.size()) {
        c.push_back(b[i++]);
    }

    c=cancel_decu(c);
    for(string& s:c) {
        cout<<s<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}