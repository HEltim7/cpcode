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
constexpr int N=6;
constexpr array<int,9> pw={0,1,10,100,1000,10000,100000,1000000,10000000};

void solve() {
    int a,b,c;
    LL k;
    cin>>a>>b>>c>>k;

    for(int i=pw[a];i<pw[a+1];i++) {
        int l=pw[b],r=pw[b+1]-1;
        int s=pw[c]-i,t=pw[c+1]-1-i;
        if(s>r||t<l) continue;
        
        s=max(s,l);
        t=min(t,r);
        int len=t-s+1;
        if(k<=len) {
            t=s+k-1;
            cout<<i<<" + "<<t<<" = "<<i+t<<endl;
            return;
        }
        else k-=len;
    }
    cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}