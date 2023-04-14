#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,x,p;
    cin>>n>>x>>p;
    bool ans=0;
    for(int i=1,cur=x;i<=min(2*n,p);i++) {
        cur=(cur+i)%n;
        if(cur==0) ans=1;
    }
    cout<<(ans?"Yes":"No")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}