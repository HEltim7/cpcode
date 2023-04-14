#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
string fb;

void init() {
    for(int i=1;i<=100;i++) {
        if(i%3==0) fb.push_back('F');
        if(i%5==0) fb.push_back('B');
    }
}

void solve() {
    string s;
    cin>>s>>s;
    for(int i=0;i<fb.size();i++) {
        for(int j=0;j<s.size();j++) {
            if(i+j>=fb.size()||fb[i+j]!=s[j]) break;
            if(j+1==s.size()) {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    init();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}