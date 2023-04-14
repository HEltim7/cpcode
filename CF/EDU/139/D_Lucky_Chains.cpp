#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int M=1e7+10;
bool st[M];
int primes[M],minp[M],idx;

void init(int n) {
    st[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!st[i]) primes[idx++]=i,minp[i]=i;
        for(int j=0;primes[j]<=n/i;j++) {
            st[primes[j]*i]=true;
            minp[primes[j]*i]=primes[j];
            if(i%primes[j]==0) break;
        }
    }
}

vector<int> get(int x) {
    vector<int> res;
    while(x>1) {
        int cur=minp[x];
        res.push_back(cur);
        while(minp[x]==cur) x/=cur;
    }
    return res;
}

void solve() {
    int x,y;
    cin>>x>>y;
    if(x+1==y) cout<<-1<<endl;
    else {
        int ans=1e9;
        for(auto p:get(y-x))
            ans=min(ans,(x+p-1)/p*p-x);
        cout<<ans<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init(1e7);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}