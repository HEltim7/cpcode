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
    bool flag=s.front()=='1';
    for(int i=1;i<n;i++) {
        int x=s[i];
        if(x=='1') {
            cout<<(flag?'-':'+');
            flag^=1;
        }
        else cout<<'+';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}