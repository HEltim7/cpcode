#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    reverse(t.begin(), t.end());
    auto cnt=vector<vector<int>>(26,vector<int>(26));
    auto tot=vector<int>(26);

    for(int i=0;i<s.size();i++) {
        int x=s[i]-'a';
        int y=t[i]-'a';
        if(x>y) swap(x,y);
        tot[x]++;
        tot[y]++;
        cnt[x][y]++;
    }
    for(int i=0;i<26;i++) if(tot[i]&1) {
        cout<<"NO"<<endl;
        return;
    }

    int odd=0;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            odd+=cnt[i][j]&1;
    if(odd==0||(odd==1&&(n&1))) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}