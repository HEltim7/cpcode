#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    int seg=0;
    bool pre=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in&&!pre) seg++,pre=1;
        if(!in) pre=0;
    }
    cout<<min(seg,2)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}