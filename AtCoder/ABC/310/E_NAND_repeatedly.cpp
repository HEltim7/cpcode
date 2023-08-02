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

    LL ans=0;
    for(int i=1,pre=0;i<=n;i++) {
        if(s[i-1]=='1') {
            pre++;
            ans+=(pre+1)/2+(pre%2&&pre<i)+(pre%2==0)*max(0,i-pre-1);
        }
        else pre=0,ans+=i-1;
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}