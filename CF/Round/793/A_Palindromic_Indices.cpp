#include<vector>
#include<iostream>
#include<algorithm>
#include<random>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,ans=0;
    string s;
    cin>>n>>s;
    if(n&1) {
        ans++;
        for(int i=n/2,j=i+1;i>=0&&j<n&&s[i]==s[j];i--,j++) ans+=2;
    }
    else{
        for(int i=n/2,j=i;i>=0&&j<n&&s[i]==s[j];i--,j++) ans+=2;
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