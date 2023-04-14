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
    if(s==string(n,'1')) cout<<"DRAW"<<endl;
    else {
        int cnt=0;
        for(auto x:s) cnt+=x=='0';
        bool mid=(n%2)&&s[n/2]=='0';
        int t=cnt/2;
        
        if(cnt==1) cout<<"BOB"<<endl;
        else {
            if(mid) cout<<"ALICE"<<endl;
            else cout<<"BOB"<<endl;
        }
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