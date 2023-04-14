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
    char minn='z';
    for(char x:s) minn=min(minn,x);
    for(int i=n-1;i>=0;i--) {
        if(s[i]==minn) {
            cout<<s[i];
            for(int j=0;j<n;j++) {
                if(i!=j) {
                    cout<<s[j];
                }
            }
            break;
        }
    }
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