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
    int cnt=0;
    for(int i=0;i<n;i++) if(s[i]=='0') cnt++;
    if(cnt&1) cout<<"NO"<<endl;
    else if(s.front()=='0'||s.back()=='0') cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        string a(n,'#'),b(n,'#');
        a.front()=b.front()='(';
        a.back()=b.back()=')';
        for(int i=1,x=1,y=1;i<n-1;i++) {
            if(s[i]=='0') {
                if(x) a[i]='(',b[i]=')';
                else a[i]=')',b[i]='(';
                x^=1;
            }
            else {
                if(y) a[i]=b[i]='(';
                else a[i]=b[i]=')';
                y^=1;
            }
        }
        cout<<a<<endl<<b<<endl;
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