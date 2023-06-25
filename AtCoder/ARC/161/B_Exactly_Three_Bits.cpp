#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
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
    LL n;
    cin>>n;
    if(n<7) {
        cout<<-1<<endl;
        return;
    }
    using BS=bitset<64>;
    BS bs=n;

    if(bs.count()>=3) {
        for(int i=63,cnt=0;i>=0;i--) {
            if(bs[i]&&++cnt>3) bs[i]=0;
        }
    }
    else if(bs.count()==2&&bs._Find_first()>=2) {
        int idx=bs._Find_first();
        bs[idx]=0;
        bs[idx-1]=1;
        bs[idx-2]=1;
    }
    else {
        if(bs.count()==2) bs[bs._Find_first()]=0;
        int idx=bs._Find_first();
        bs[idx]=0;
        bs[idx-1]=bs[idx-2]=bs[idx-3]=1;
    }
    cout<<bs.to_ullong()<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}