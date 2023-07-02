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

void solve() {
    int n,r,c;
    cin>>n>>r>>c;
    
    vector<tuple<int,int,int,int>> ans;
    int r1=1,r2=n,c1=1,c2=n;
    while(r1!=r2||c1!=c2) {
        if(r1!=r) {
            if(c1!=c) {
                ans.emplace_back(r1,c1,r2-r1,c2-c1);
                r1++,c1++;
            }
            else {
                ans.emplace_back(r1,c2,r2-r1,c1-c2);
                r1++,c2--;
            }
        }
        else {
            if(c1!=c) {
                ans.emplace_back(r2,c1,r1-r2,c2-c1);
                r2--,c1++;
            }
            else {
                ans.emplace_back(r2,c2,r1-r2,c1-c2);
                r2--,c2--;
            }
        }
    }

    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
    for(auto [a,b,c,d]:ans) cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}