#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int cnt[N];

void count(int x) {
    for(int i=1;i*i<=x;i++) {
        if(x%i==0) {
            int j=x/i;
            if(i==j) cnt[x]++;
            else cnt[x]+=2;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) count(i);
    LL ans=0;
    for(int i=1;i<=n;i++) ans+=1LL*cnt[i]*cnt[n-i];
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}