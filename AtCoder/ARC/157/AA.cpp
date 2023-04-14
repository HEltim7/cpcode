#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int xxyy=n-1-b-c;
    if(!b&&!c) {
        if(n==2||!a||!d) cout<<"Yes";
        else cout<<"No";
    }
    else {
        if(a+d==xxyy&&abs(b-c)<=1) cout<<"Yes";
        else cout<<"No";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}