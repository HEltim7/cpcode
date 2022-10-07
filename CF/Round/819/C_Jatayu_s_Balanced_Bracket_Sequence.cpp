#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    n*=2;
    string s;
    cin>>s;
    vector<int> stk;

    int cur=0;
    LL ans=0;
    for(auto x:s) {
        if(x=='(') {
            cur++;
            if(stk.empty()||stk.back()<cur) ans++;
            while(stk.size()&&stk.back()>cur) stk.pop_back();
            stk.push_back(cur);
        }
        else cur--;
    }
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