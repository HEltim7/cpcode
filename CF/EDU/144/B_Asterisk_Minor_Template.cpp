#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s,t;
    cin>>s>>t;
    if(s.front()==t.front()) {
        cout<<"YES"<<endl;
        cout<<s.front()<<"*"<<endl;
    }
    else if(s.back()==t.back()) {
        cout<<"YES"<<endl;
        cout<<"*"<<s.back()<<endl;
    }
    else {
        for(int i=1;i<s.size();i++) {
            for(int j=1;j<t.size();j++) {
                if(s[i]==t[j]&&s[i-1]==t[j-1]) {
                    cout<<"YES"<<endl;
                    cout<<"*"<<s[i-1]<<s[i]<<"*"<<endl;
                    return;
                }
            }
        }
        cout<<"NO"<<endl;
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