#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    if(n<=3||n==7) cout<<"-1"<<endl;
    else {
        auto put4=[](int idx) {
            cout<<idx+2<<' '<<idx+3<<' '<<idx<<' '<<idx+1<<' ';
        };
        auto put5=[](int idx) {
            cout<<idx+3<<' '<<idx+4<<' '<<idx<<' '<<idx+1<<' '<<idx+2<<' ';
        };
        auto put6=[](int idx) {
            cout<<idx+3<<' '<<idx+4<<' '<<idx+5<<' '<<idx<<' '<<idx+1<<' '<<idx+2<<' ';
        };

        int idx=1;
        if(n&1) put5(idx),idx+=5;
        while(idx<n) {
            if(n-idx+1==6) put6(idx),idx+=6;
            else put4(idx),idx+=4;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}