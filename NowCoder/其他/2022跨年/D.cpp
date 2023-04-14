#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    while(c%a==0) c/=a;
    while(c%b==0) c/=b;
    if(c==1) cout<<"YES";
    else cout<<"NO";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}