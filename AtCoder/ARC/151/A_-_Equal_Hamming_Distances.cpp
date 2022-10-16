#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s,t;
    cin>>n>>s>>t;
    int cnt=0,val=0;
    for(int i=0;i<n;i++) {
        cnt+=s[i]!=t[i];
        if(s[i]=='0'&&t[i]=='1') val++;
        else if(s[i]=='1'&&t[i]=='0') val--;
    }
    val/=2;
    if(cnt&1) cout<<-1<<endl;
    else {
        string res(n,'0');
        for(int i=n-1;i>=0&&val;i--) {
            if(val>0&&s[i]=='0'&&t[i]=='1') {
                val--;
                res[i]='1';
            }
            else if(val<0&&s[i]=='1'&&t[i]=='0') {
                val++;
                res[i]='1';
            }
        }
        assert(val==0);
        cout<<res<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}