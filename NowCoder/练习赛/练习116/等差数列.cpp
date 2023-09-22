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

void solve() {
    LL a,k,q;
    cin>>a>>k>>q;
    a&=1,k&=1;
    while(q--) {
        LL l,r;
        cin>>l>>r;
        bool st=((l-1)*k)&1;
        st^=a;
        if(!k) {
            if(st) cout<<1<<endl;
            else cout<<-1<<endl;
        }
        else {
            if(((r-l+1)&1)) {
                if(st) cout<<1<<endl;
                else cout<<-1<<endl;
            }
            else cout<<0<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}