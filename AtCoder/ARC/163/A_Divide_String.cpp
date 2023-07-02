#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s=" "+s;
    for(int i=2;i<=n;i++) {
        if(s[i]>s[1]) {
            cout<<"Yes"<<endl;
            return;
        }
    }

    for(int len=1;len+1<=n;len++) {
        for(int i=1,j=len+1;i<=len&&j<=n;i++,j++) {
            if(s[i]>s[j]) break;
            if(s[i]<s[j]) {
                cout<<"Yes"<<endl;
                return;
            }
        }
    }

    for(int len=1;len*2+1<=n;len++) {
        for(int i=1,j=len+1;i<=len+1;i++,j++) {
            if(i==len+1) {
                cout<<"Yes"<<endl;
                return;
            }
            if(s[i]>s[j]) break;
        }
    }

    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}