#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s,ans;
    cin>>n>>s;
    bool flag=0;
    for(int i=0;i<n;i++) {
        if(ans.empty()||s[i]<s[i-1]||s[i]<=s[i-1]&&flag)
            ans.push_back(s[i]);
        else break;
        if(i&&s[i]!=s[i-1]) flag=1;
    }
    cout<<ans;
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