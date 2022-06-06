#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a,b,c;
    cin>>a>>b>>c;
    if(b>=a&&b<=c||b>=c&&b<=a) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}