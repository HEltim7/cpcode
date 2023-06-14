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

#define endl '\n'
using LL=long long;

void solve() {
    int q;
    cin>>q;
    int bg=-1,mid=-1,last=-1;
    while(q--) {
        int x;
        cin>>x;
        if(last==-1) {
            cout<<1;
            bg=last=x;
        }
        else if(mid==-1) {
            if(x<last) {
                if(x<=bg) {
                    cout<<1;
                    last=mid=x;
                }
                else cout<<0;
            }
            else {
                cout<<1;
                last=x;
            }
        }
        else {
            if(x>=last&&x<=bg) {
                cout<<1;
                last=x;
            }
            else cout<<0;
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}