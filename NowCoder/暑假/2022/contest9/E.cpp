#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int B=40;
int res[B];

void solve() {
    int n,ans=0,cnt=0;
    cin>>n;
    int hbit=__lg(n);
    memset(res, 0, sizeof(res));
    for(int i=hbit,idx=1;~i;i--) {
        if(n&(1<<i)) res[i]=idx,cnt+=idx,idx=0;
        idx++;
    }
    ans=cnt+hbit*2;
    assert(ans<=100);
    cout<<ans<<endl;
    for(int i=hbit,lower=0,upper=cnt;~i;i--) {
        for(int j=1;j<=res[i];j++) cout<<++lower<<' ';
        if(i) {
            cout<<upper+2<<' '<<upper+1<<' ';
            upper+=2;
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