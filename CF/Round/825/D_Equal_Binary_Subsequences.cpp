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
    vector<int> cnt(2);
    string s;
    cin>>s;
    for(auto x:s) cnt[x-'0']++;
    if(cnt[0]&1||cnt[1]&1) cout<<"-1"<<endl;
    else {
        s=" "+s;
        vector<int> res;
        for(int i=1,cur=0;i<=n;i+=2) {
            if(s[i]!=s[i+1]) {
                if(s[i]-'0'==cur) res.push_back(i);
                else res.push_back(i+1);
                cur^=1;
            }
        }
        cout<<res.size()<<' ';
        for(auto x:res) cout<<x<<' ';
        cout<<endl;
        for(int i=1;i<=n;i+=2) cout<<i<<' ';
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}