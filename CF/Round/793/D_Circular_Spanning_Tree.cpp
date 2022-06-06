#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    for(auto x:s) if(x=='1') cnt++;
    if((cnt&1)||cnt<2) {
        cout<<"NO"<<endl;
        return ;
    }
    cout<<"YES"<<endl;
    s+=s;
    int idx;
    for(int i=0;i<n;i++) if(s[i]=='1') {
        idx=i;
        break;
    }
    int tail=-1;
    for(int i=idx;i<idx+n;i++) {
        if(s[i+1]=='1'&&tail==-1) tail=i;
        else if(s[i+1]=='1') cout<<i%n+1<<' '<<tail%n+1<<endl;
        else if(s[i+1]=='0') cout<<i%n+1<<' '<<(i+1)%n+1<<endl;
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