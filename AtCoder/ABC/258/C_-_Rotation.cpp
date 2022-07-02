#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,q;
    string s;
    cin>>n>>q>>s;
    s=" "+s;
    int cnt=0;
    while(q--) {
        int op,x;
        cin>>op>>x;
        if(op==1) {
            cnt=(cnt+x)%n;
        }
        else {
            if(x>cnt) cout<<s[x-cnt]<<endl;
            else cout<<s[x+(n-cnt)]<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}