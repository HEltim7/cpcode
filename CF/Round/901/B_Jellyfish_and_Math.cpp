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
vector<int> ans[2][4][4]; //ans[m][x,y]->[c,d];

void init() {
    for(int i=0;i<4;i++) ans[0][i][0].emplace_back(1);
    ans[1][0][1].emplace_back(4);
    // ans[1][1][0].emplace_back()

    ans[1][2][0]={1};
    ans[1][2][1]={1,4};
    
}

void solve() {
    int a,b,c,d,m;
    cin>>a>>b>>c>>d>>m;

    bool has_one=false;
    bool no_one=false;
    for(int i=0;i<30;i++) {
        int x=(a>>i&1)<<1|(b>>i&1);
        int y=(c>>i&1)<<1|(d>>i&1);
        int z=m>>i&1;
        if(!z) {
            if(y==0) {
                if(x!=0) has_one=true;
            }
            else {
                if(x!=y) {
                    cout<<-1<<endl;
                    return;
                }
                else no_one=true;
            }
        }
    }

    if(has_one&&no_one) {
        cout<<-1<<endl;
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}