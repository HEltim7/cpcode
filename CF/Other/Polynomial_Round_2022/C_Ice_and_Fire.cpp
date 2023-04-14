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
    char pre='!';
    for(int i=0,cnt=0;i<n-1;i++) {
        int x=s[i];
        if(x==pre) cnt++;
        else pre=x,cnt=1;
        cout<<i+2-cnt<<' ';
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