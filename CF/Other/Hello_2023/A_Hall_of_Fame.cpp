#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    for(int i=0;i<n-1;i++) {
        if(s[i]=='R'&&s[i+1]=='L') {
            cout<<0<<endl;
            return;
        }
        else if(s[i]=='L'&&s[i+1]=='R') {
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}