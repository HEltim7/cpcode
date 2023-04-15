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
    
    if(find(s.begin(),s.end(),'o')!=s.end()&&find(s.begin(),s.end(),'x')==s.end()) 
        cout<<"Yes";
    else cout<<"No";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}