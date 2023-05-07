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
    reverse(s.begin(),s.end());

    string ans;
    for(int i=0;i<s.size();i++) {
        if(s[i]!='0') {
            int c=s[i]-'0';
            int cur=10-c;
            ans.push_back(char(cur+'0'));
            break;
        }
        else ans.push_back('0');
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}