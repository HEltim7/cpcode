#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    map<string,int> mp;
    int n;
    string s;
    cin>>n>>s;

    for(int i=1;i<n;i++) {
        string cur=string{}+s[i-1]+s[i];
        if(!mp[cur]) mp[cur]=i;
        if(i-mp[cur]>=2) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}