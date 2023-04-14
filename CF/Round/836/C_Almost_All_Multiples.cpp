#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int M=2e5+10;
int primes[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) primes[++idx]=i,minp[i]=i;
        for(int j=1;primes[j]<=n/i;j++) {
            isnp[primes[j]*i]=true;
            minp[primes[j]*i]=primes[j];
            if(i%primes[j]==0) break;
        }
    }
}

vector<int> get_factor(int val) {
    vector<int> res;
    while(val>1) {
        res.push_back(minp[val]);
        val/=minp[val];
    }
    return res;
}

void solve() {
    int n,x;
    cin>>n>>x;
    if(n%x==0) {
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++) arr[i]=i;
        auto p=get_factor(n/x);
        for(int cur=x; auto x:p) arr[cur]=cur*x,cur*=x;
        arr[1]=x;
        arr[n]=1;
        for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
    }
    else cout<<-1<<endl;
}

int main() {
    get_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}