#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
constexpr LL lim=1e13,sq=3162277;

void solve() {
    static_assert(sq*sq<=lim&&(sq+1)*(sq+1)>lim, "");

    int n;
    string s;
    cin>>n>>s;
    int zero=0;
    sort(s.begin(),s.end(),greater<>());
    while(s.size()&&s.back()=='0') s.pop_back(),zero++;

    int ans=0;
    for(LL i=0;i<=sq;i++) {
        string t=to_string(i*i);
        int cur=0;
        sort(t.begin(),t.end(),greater<>());
        while(t.size()&&t.back()=='0') t.pop_back(),cur++;
        if(s==t&&cur<=zero) ans++;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}