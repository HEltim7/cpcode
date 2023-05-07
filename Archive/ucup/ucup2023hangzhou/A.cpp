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
using namespace std;

using LL=long long;

void solve() {
    int n;
    cin>>n;

    int cnt=0;
    auto ask=[&](int x) {
        assert(++cnt<=40);
        cout<<"? "<<x<<endl;
        int in;
        cin>>in;
        return in;
    };
    auto fin=[&](int x) {
        cout<<"! "<<x<<endl;
    };

    int L=0,R=0;
    for(int i=1;i<=min(n,20);i++) {
        int cur=ask(i);
        if(cur==L) {
            fin(i);
            return;
        }
        else L++;
    }

    int l=min(n,20)+1,r=n;
    while(l<r) {
        int mid=l+r>>1;
        int cur=ask(mid);
        if(cur==L-R) {
            fin(mid);
            return;
        }
        else if(cur>L-R) {
            L++;
            l=mid+1;
        }
        else {
            R++;
            r=mid-1;
        }
    }

    fin(l);
}

int main() {
    ios::sync_with_stdio(0);
    solve();
    return 0;
}