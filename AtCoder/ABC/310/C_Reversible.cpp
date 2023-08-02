#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    int n;
    cin>>n;
    set<string> st;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        if(st.find(s)!=st.end()) continue;
        reverse(s.begin(),s.end());
        if(st.find(s)!=st.end()) continue;
        st.insert(s);
    }
    cout<<st.size()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}