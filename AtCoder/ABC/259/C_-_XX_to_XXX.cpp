#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    if(n>m) {
        cout<<"No";
        return;
    }
    bool ans=0;
    for(int i=-1,j=-1;i<n&&j<m;) {
        if(i+1<n&&j+1<m&&s[i+1]==t[j+1]) i++,j++;
        else {
            if(i-1>=0&&s[i]==s[i-1]&&s[i]==t[j+1]) j++;
            else break;
        }
        if(i+1==n&&j+1==m) ans=1;
    }
    if(ans) cout<<"Yes";
    else cout<<"No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}