#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int M=1e5+10;
bool st[M];
int primes[M],minp[M],idx;
unordered_set<int> ust;
int arr[M];

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

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];

    auto insert=[&](const int &x) {
        if(ust.count(x)) {
            cout<<"YES"<<endl;
            return true;
        }
        ust.insert(x);
        return false;
    };

    ust.clear();
    for(int i=1;i<=n;i++) {
        for(int j=idx-1;j>=0;j--) {
            if(arr[i]%primes[j]==0) {
                if(insert(primes[j])) return;
                while(arr[i]%primes[j]==0) arr[i]/=primes[j];
            }
        }
        if(arr[i]>1&&insert(arr[i])) return;
    }

    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init(3.2e4);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}