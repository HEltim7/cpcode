#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    string s;
    cin>>s;
    for(int len=s.size();len>=1;len--) {
        for(int i=0,j=i+len-1;j<s.size();i++,j++) {
            for(int l=j+1,r=j+len;r<s.size();l++,r++) {
                bool flag=1;
                for(int k=0;k<len;k++) {
                    if(s[i+k]!=s[l+k]) {
                        flag=0;
                        break;
                    }
                }
                if(flag) {
                    for(int k=i;k<=j;k++) cout<<s[k];
                    cout<<endl;
                    return;
                }
            }
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