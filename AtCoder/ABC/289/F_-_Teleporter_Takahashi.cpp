#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(abs(sx-tx)%2||abs(sy-ty)%2) {
        cout<<"No"<<endl;
        return;
    }

    vector<pair<int,int>> res;

    auto tp=[&](int r,int c) {
        sx=2*r-sx;
        sy=2*c-sy;
        res.emplace_back(r,c);
    };

    if(c==d&&sy!=ty) tp(a,c);
    if(a==b&&sx!=tx) tp(a,c);

    while(sx<tx) {
        tp(a,c);
        if(a+1>b) break;
        else tp(a+1,c);
    }
    while(sx>tx) {
        tp(b,c);
        if(b-1<a) break;
        else tp(b-1,c);
    }

    while(sy<ty) {
        tp(a,c);
        if(c+1>d) break;
        else tp(a,c+1);
    }
    while(sy>ty) {
        tp(a,d);
        if(d-1<c) break;
        else tp(a,d-1);
    }

    if(sx==tx&&sy==ty) {
        cout<<"Yes"<<endl;
        for(auto [x,y]:res) cout<<x<<' '<<y<<endl;
    }
    else cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}