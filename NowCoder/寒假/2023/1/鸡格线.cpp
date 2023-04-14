#include <map>
#include <cmath>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    multimap<int,int> mp;
    int n,m;
    LL sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        sum+=in;
        if(in!=100&&in!=99&&in) mp.emplace(i,in);
    }
    for(int i=1;i<=m;i++) {
        int op,l,r,k;
        cin>>op;
        if(op==1) {
            cin>>l>>r>>k;
            auto lit=mp.lower_bound(l);
            auto rit=mp.upper_bound(r);
            while(lit!=rit) {
                for(int i=1;i<=k&&lit->second!=100&&lit->second!=99;i++) {
                    int t=lit->second;
                    lit->second=round(10*sqrt(lit->second));
                    sum+=lit->second-t;
                }
                if(lit->second==100||lit->second==99) lit=mp.erase(lit);
                else lit++;
            }
        }
        else cout<<sum<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}