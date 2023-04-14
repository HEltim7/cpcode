#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string a,b;
    cin>>n>>a>>b;
    a=" "+a,b=" "+b;
    int dif=0;
    for(int i=1;i<=n;i++) if(a[i]!=b[i]) dif++;
    if(dif==0||dif==n) {
        cout<<"Yes"<<endl;
        vector<pair<int,int>> res;
        auto flip=[](char &x) { x=x=='1'?'0':'1'; };
        if(dif==n) {
            res.emplace_back(1,1);
            flip(a[1]);
            for(int i=2;i<=n;i++) flip(b[i]);
        }

        auto fn=[&](int l,int r) {
            if(r==n) {
                res.emplace_back(l-1,r);
                res.emplace_back(l-1,l-1);
            }
            else {
                res.emplace_back(l,r+1);
                res.emplace_back(r+1,r+1);
            }
        };

        for(int i=1,j=1;i<=n;) {
            while(i<=n&&a[i]!='1') i++;
            j=i;
            if(i>n) break;
            while(j+1<=n&&a[j+1]=='1') j++;
            
            if(i==1&&j==n) fn(i,j-1),fn(j,j);
            else fn(i,j);
            i=j+1;
        }

        assert(res.size()<=n+5);
        cout<<res.size()<<endl;
        for(auto [x,y]:res) cout<<x<<' '<<y<<endl;
    }
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}