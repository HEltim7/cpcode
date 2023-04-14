#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using LL=long long;

void solve() {
    int n,m;
    cin>>n>>m;
    auto ask=[&](int r,int c) {
        cout<<"? "<<r<<' '<<c<<endl;
        int in;
        cin>>in;
        return in;
    };
    auto fin=[&](int r,int c) {
        cout<<"! "<<r<<' '<<c<<endl;
    };

    int dis=ask(1,1);
    if(dis==0) {
        fin(1,1);
        return;
    }

    int r=min(n,dis+1);
    int c=min(m,dis+1);
    int dis2=ask(r,c);
    if(dis2==0) {
        fin(r,c);
        return;
    }

    int x1=r;
    int y1=c-dis2;
    int x2=r-dis2;
    int y2=c;

    if(y1<1) fin(x2,y2);
    else if(x2<1) fin(x1,y1);
    else {
        int dis3=ask(x1,y1);
        if(dis3==0) fin(x1,y1);
        else fin(x2,y2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}