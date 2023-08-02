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
    for(int i=1,cnta=0,cntb=0;i<=n;i++) {
        if(s[i-1]=='A') cnta++;
        else cntb++;

        int alice=(i+1)/2;
        int bob=i-alice;
        if(alice>=cntb&&bob>=cnta) {
            if(s[i]=='A') cout<<"Alice"<<endl;
            else cout<<"Bob"<<endl;
        }
        else if(alice>=cntb) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}