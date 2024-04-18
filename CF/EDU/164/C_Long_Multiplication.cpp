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
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s,t,x,y;
    cin>>s>>t;
    for(int i=0,flag=false;i<s.size();i++) {
        if(!flag) {
            if(s[i]==t[i]) x.push_back(s[i]),y.push_back(t[i]);
            else x.push_back(min(s[i],t[i])),y.push_back(max(s[i],t[i])),flag=true;
        }
        else x.push_back(max(s[i],t[i])),y.push_back(min(s[i],t[i]));
    }
    cout<<x<<endl<<y<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}