#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int cnt[]={0,0,0};
    int n;
    cin>>n;
    string s[2],sac[2];
    vector<int> pre[2],suf[2];
    cin>>s[0]>>s[1];
    for(int z=0;z<=1;z++) {
        for(auto x:s[z]) if(z) cnt[x-'a']++; else cnt[x-'a']--;
        for(auto x:s[z]) if(x!='b') sac[z].push_back(x);
        for(int i=0,bcnt=0;i<n;i++) 
            if(s[z][i]=='b') bcnt++;
            else if(s[z][i]=='c') pre[z].push_back(bcnt);
        for(int i=n-1,bcnt=0;i>=0;i--)
            if(s[z][i]=='b') bcnt++;
            else if(s[z][i]=='a') suf[z].push_back(bcnt);
    }
    if(cnt[0]||cnt[1]||cnt[2]||sac[0]!=sac[1]) {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=0;i<pre[0].size();i++) 
        if(pre[0][i]<pre[1][i]) {
            cout<<"NO"<<endl;
            return;
        }
    for(int i=0;i<suf[0].size();i++)
        if(suf[0][i]<suf[1][i]) {
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}