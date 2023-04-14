#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    vector<string> v{"and", "not", "that", "the", "you"};
    int n;
    cin>>n;
    while(n--) {
        string s;
        cin>>s;
        if(find(v.begin(),v.end(),s)!=v.end()) {
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}