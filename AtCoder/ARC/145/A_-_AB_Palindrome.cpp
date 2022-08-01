#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==2) {
        if(s.front()==s.back()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else {
        if(s.front()=='B'||s.back()=='A') cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}