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

vector<int> zfunc(const string &s) {
    int n=s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0;i<n;i++) {
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        while(i+z[i]<n&&s[i+z[i]]==s[z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
    return z;
}

void solve() {
    string a,b;
    cin>>a>>b;
    auto &&z=zfunc(b);
    z[0]=b.size();
    
    LL ans=0;
    for(int i=1;i<=z.size();i++) ans^=1LL*i*(z[i-1]+1);
    cout<<ans<<endl;
    
    ans=0;
    z=std::move(zfunc(b+"#"+a));
    int n=b.size();
    for(int i=1;i<=a.size();i++) ans^=1LL*i*(z[n+i]+1);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}