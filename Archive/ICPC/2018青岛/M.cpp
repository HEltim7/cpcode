#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int en[]={1,0,0,0,1,0,1,0,2,1};

void solve() {
    int x,k;
    cin>>x>>k;
    while(k&&x>1) {
        int t=0;
        for(char c:to_string(x)) {
            t+=en[c-'0'];
        }
        x=t;
        k--;
    }
    if(k&&(k&1)) x^=1;
    cout<<x<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}