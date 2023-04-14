#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;
    for(int i=1;i+1<s.size();i++) {
        if(s[i]=='a') {
            for(int j=0;j<i;j++) cout<<s[j];
            cout<<' '<<'a'<<' ';
            for(int j=i+1;j<s.size();j++) cout<<s[j];
            cout<<endl;
            return;
        }
    }
    cout<<s.front()<<' ';
    for(int i=1;i+1<s.size();i++) cout<<s[i];
    cout<<' '<<s.back()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}