#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    int r[3],c[3];
    cin>>n;
    for(int i=0;i<3;i++) cin>>r[i]>>c[i];
    auto check=[&](int i,int j) {
        if(r[i]==r[j]||c[i]==c[j]) return 1;
        return 0;
    };
    int x,y;
    for(int i=0;i<3;i++) {
        int cnt=0;
        for(int j=0;j<3;j++)
            cnt+=check(i,j);
        if(cnt==3) {
            x=r[i];
            y=c[i];
        }
    }

    int row,col;
    cin>>row>>col;
    debug(x,y,row,col);

    if((x==1||x==n)&&(y==1||y==n)) {
        if(row==x||col==y) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }

    if(abs(row-x)%2&&abs(col-y)%2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}