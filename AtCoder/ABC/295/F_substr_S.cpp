#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=18;
LL pw[N];

LL solve(string s,LL r) {
    string t=to_string(r);
    // reverse(s.begin(),s.end());
    // reverse(t.begin(),t.end());
    bool flag=s>t;
    int sl=s.size()-1,tl=s.size()-1;
    for(int k=sl;k<=tl-flag;k++) {
        
    }
}

void solve() {
    string s;
    LL l,r;
    cin>>s>>l>>r;

    
}

int main() {
    pw[0]=1;
    for(int i=1;i<N;i++) pw[i]=pw[i-1]*10;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}