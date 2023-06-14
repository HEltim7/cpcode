#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
#include <cmath>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int M=1e6+10;
int prime[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

vector<int> get_factor(int val) {
    vector<int> res;
    while(val>1) {
        int t=minp[val];
        int cnt=0;
        while(minp[val]==t) val/=t,cnt++;
        if(cnt&1) res.push_back(t);
    }
    return res;
}

void solve() {
    constexpr int N=200;
    get_prime(N);
    int x=sqrt(N);
    cerr<<x<<endl;

    int cnt=0;
    for(int i=1;i<=x;i++) {
        if(!isnp[i]) {
            cnt++;
            cerr<<i<<' ';
        }
    }
    cerr<<endl;
    cerr<<"tot="<<cnt<<endl;
    cnt=0;
    for(int i=x+1;i<=N;i++) {
        if(!isnp[i]) {
            cnt++;
            cerr<<i<<' ';
        }
    }
    cerr<<endl;
    cerr<<"tot="<<cnt<<endl;
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}

/*

*/