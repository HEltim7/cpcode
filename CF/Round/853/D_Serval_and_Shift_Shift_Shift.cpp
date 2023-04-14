#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;

void solve() {
    int n;
    bitset<N> s,t;
    cin>>n>>s>>t;
    if(s==t) {
        cout<<0<<endl;
        return;
    }
    if(s.none()!=t.none()) {
        cout<<-1<<endl;
        return;
    }

    int rev=1;
    vector<int> res;

    auto mv=[&](int len) {
        s^=s<<len;
        res.emplace_back(len*rev);
    };

    auto reverse=[&]() {
        rev*=-1;
        for(int idx=0; auto x:s.to_string()) s[idx++]=x-'0';
        for(int idx=0; auto x:t.to_string()) t[idx++]=x-'0';
        s>>=N-n;
        t>>=N-n;
    };

    if(s._Find_first()>t._Find_first()) reverse();
    for(int p=s._Find_first(),i=p+1;i<n;i++) if(s[i]!=t[i]) mv(i-p);
    reverse();
    for(int p=s._Find_first(),i=p+1;i<n;i++) if(s[i]!=t[i]) mv(i-p);
    
    cout<<res.size()<<endl;
    for(int i:res) cout<<i<<' ';
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