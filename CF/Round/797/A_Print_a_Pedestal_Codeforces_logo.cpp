#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    int t=n/3;
    int l=n%3;
    int a=t-1,b=t,c=t+1;
    if(l) c++,l--;
    if(l) b++,l--;
    cout<<b<<' '<<c<<' '<<a<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}